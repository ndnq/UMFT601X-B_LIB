#ifndef UMFT601X
#define UMFT601X

#include <iostream>
#include "../FTD3XX/FTD3XX.h"

//Funkcje zwiazane z identyfikacja urzadzenia
void listDeviceInfo();
FT_HANDLE openDeviceBySerialNumber(std::string serialNumber);
void closeDevice(FT_HANDLE ftHandle);
#endif