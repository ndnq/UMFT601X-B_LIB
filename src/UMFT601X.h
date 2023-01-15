#ifndef UMFT601X
#define UMFT601X

#include <iostream>
#include "../FTD3XX/FTD3XX.h"
//Szerokość buforu w bajtach 
#define BUFFER_WIDTH 16

//Funkcje zwiazane z identyfikacja urzadzenia
void            listDeviceInfo();
FT_HANDLE       openDeviceBySerialNumber    (std::string serialNumber);
void            closeDevice                 (FT_HANDLE ftHandle);
//  Funkcje pisania i czytania z kolejki
//  Pipe id to:
/// 0 0x01 OUT BULK endpoint for Session List commands
/// 0x81 IN INTERRUPT endpoint for Notification List commands
/// 1 0x02-0x05 OUT BULK endpoint for application write access
/// 0x82-0x85 IN BULK endpoint for application read access

void            writeToPipe                 (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char value);
unsigned char   readFromPipe                (FT_HANDLE ftHandle, unsigned char pipeId   );
void            writeBufferToPipe           (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char* buffer);
void            readBufferFromPipe          (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char* buffer);

#endif