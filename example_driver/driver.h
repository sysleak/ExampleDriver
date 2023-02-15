#pragma once

#include <ntifs.h>
#include <ntddk.h>
#include <wdf.h>

#define log( text, ... ) DbgPrintEx( 0, 0, text, __VA_ARGS__ );

#pragma region drv_data_structs

typedef struct _orig_drv_data
{
	PDRIVER_OBJECT drv_obj;
	PUNICODE_STRING path;
} orig_drv_data, * porig_drv_data;

#pragma endregion drv_data_structs

orig_drv_data stored_orig_data;

void Sleep( int ms );

NTSTATUS StartThread( PKSTART_ROUTINE start_function, PVOID args );