#pragma once

#include <ntddk.h>

void NotifyRoutine( PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo );