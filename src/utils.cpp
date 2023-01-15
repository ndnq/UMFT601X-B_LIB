#include "UMFT601X.h"

void listDeviceInfo()
{
 std::cout << "LISTING " << std::endl;
 DWORD numDevs;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    
    FT_STATUS ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK) {
        std::cout << "Number of devices: " << numDevs << std::endl;
        if (numDevs > 0) {
            devInfo = new FT_DEVICE_LIST_INFO_NODE[numDevs];
            ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);
            if (ftStatus == FT_OK) {
                for (DWORD i = 0; i < numDevs; i++) {

                    std::cout << "Device " << i << ":" << std::endl;
                    std::cout << "  Flags: " << devInfo[i].Flags << std::endl;
                    std::cout << "  Type: " << devInfo[i].Type << std::endl;
                    std::cout << "  ID: " << devInfo[i].ID << std::endl;
                    std::cout << "  LocId: " << devInfo[i].LocId << std::endl;
                    std::cout << "  SerialNumber: " << devInfo[i].SerialNumber << std::endl;
                    std::cout << "  Description: " << devInfo[i].Description << std::endl;
                    std::cout << "  ftHandle: " << devInfo[i].ftHandle << std::endl;
                }
            } else {
                std::cout << "FT_GetDeviceInfoList failed" << std::endl;
            }
            delete[] devInfo;
        }
    } else {
        std::cout << "FT_CreateDeviceInfoList failed" << std::endl;
    }
}

FT_HANDLE openDeviceBySerialNumber(std::string serialNumber) {
    DWORD numDevs;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    FT_HANDLE ftHandle = 0;
    FT_STATUS ftStatus;

    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK) {
        if (numDevs > 0) {
            
            devInfo = new FT_DEVICE_LIST_INFO_NODE[numDevs];
            ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);
            if (ftStatus == FT_OK) {
                for (DWORD i = 0; i < numDevs; i++) {
                    std::cout << "Comparing" << std::endl;
                    if (serialNumber.compare(devInfo[i].SerialNumber) == 0) {
                        ftStatus = FT_Create(devInfo[i].SerialNumber, FT_OPEN_BY_SERIAL_NUMBER, &ftHandle);
                        if (ftStatus != FT_OK) {
                            std::cout << "Failed to open device" << std::endl;
                        } else {
                            std::cout << "Device with serial number " << serialNumber << " opened successfully" << std::endl;
                        }
                        break;
                    }
                }
            } else {
                std::cout << "Failed to list devices" << std::endl;
            }
            delete[] devInfo;
        }
    } else {
        std::cout << "Failed to list devices" << std::endl;
    }
    return ftHandle;
}

void closeDevice(FT_HANDLE ftHandle) {
    FT_STATUS ftStatus;
    ftStatus = FT_Close(ftHandle);
    if (ftStatus != FT_OK) {
        std::cout << "FT_Close failed" << std::endl;
    } else {
        std::cout << "Device handle closed successfully" << std::endl;
    }
}