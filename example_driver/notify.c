#include "driver.h"
#include "notify.h"

void NotifyRoutine( PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo ) {
	UNREFERENCED_PARAMETER( FullImageName );
	UNREFERENCED_PARAMETER( ProcessId );
	UNREFERENCED_PARAMETER( ImageInfo );
}