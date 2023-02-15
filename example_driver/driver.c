#include "driver.h"
#include "notify.h"

void Sleep( int ms ) {
	LARGE_INTEGER timeout;
	timeout.QuadPart = ms * -10000;
	KeDelayExecutionThread( KernelMode, FALSE, &timeout );
}

NTSTATUS StartThread( PKSTART_ROUTINE start_function, PVOID args ) {
	HANDLE thread_handle = NULL;

	const NTSTATUS status = PsCreateSystemThread( &thread_handle, GENERIC_ALL, NULL, NULL, NULL, start_function, args );

	if ( NT_SUCCESS( status ) ) {
		ZwClose( thread_handle );
	}

	return status;
}

VOID init_thread(  ) 
{
	// wait some time for ensure that kdmapper closed
	Sleep( 2000 );
	
	log( "thread created!\n" );

	log( "trying to load notify routine...\n" );

	NTSTATUS Status = PsSetLoadImageNotifyRoutine( NotifyRoutine );
	if ( NT_ERROR( Status ) ) {
		log( "PsSetLoadImageNotifyRoutine failed with code 0x%X!\n", Status );
	}
	else {
		log( "notify routine successfully loaded!\n" );
	}

	Sleep( 10000 );

	log( "trying to remove notify routine...\n" );

	Status = PsRemoveLoadImageNotifyRoutine( NotifyRoutine );
	if ( NT_ERROR( Status ) ) {
		log( "PsRemoveLoadImageNotifyRoutine failed with code 0x%X!\n", Status );
	}
	else {
		log( "notify routine successfully removed!\n" );
	}

	log( "exiting thread!\n" );

	return;
}

NTSTATUS main_entry( PDRIVER_OBJECT drv_obj, PUNICODE_STRING path )
{
	stored_orig_data.drv_obj = drv_obj;
	stored_orig_data.path = path;

	StartThread( ( PKSTART_ROUTINE )init_thread, NULL );
	return STATUS_SUCCESS;
}