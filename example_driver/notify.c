#include "driver.h"
#include "notify.h"

/// <summary>
/// Image notify routine
/// Executes every time when system loads any dll in some app
/// Provides info about loaded modules and processes in which this modules was loaded
/// </summary>
/// <param name="FullImageName">Contains name of image which was loaded</param>
/// <param name="ProcessId">Obviously process id</param>
/// <param name="ImageInfo">Contains detailed data about image_info</param>
void NotifyRoutine( PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo ) {
	UNREFERENCED_PARAMETER( FullImageName );
	UNREFERENCED_PARAMETER( ProcessId );
	UNREFERENCED_PARAMETER( ImageInfo );
}