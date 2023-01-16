#ifndef UMFT601X
#define UMFT601X

#include <iostream>
#include "../FTD3XX/FTD3XX.h"

//Funkcje zwiazane z identyfikacja urzadzenia
void            listDeviceInfo();
FT_STATUS       openDeviceBySerialNumber    (std::string serialNumber,FT_HANDLE* ftHandle);
void            closeDevice                 (FT_HANDLE ftHandle);

//  Funkcje pisania i czytania z kolejki
//  Pipe id to:
/// 0 0x01 OUT BULK endpoint for Session List commands
/// 0x81 IN INTERRUPT endpoint for Notification List commands
/// 1 0x02-0x05 OUT BULK endpoint for application write access
/// 0x82-0x85 IN BULK endpoint for application read access

FT_STATUS       writeToPipe                 (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char    value   );
FT_STATUS       readFromPipe                (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char*   pdata   );
void            writeBufferToPipe           (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char*   buffer, unsigned int size  );
void            readBufferFromPipe          (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char*   buffer, unsigned int size  );

#endif