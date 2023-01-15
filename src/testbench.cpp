#include "UMFT601X.h"
int main() {

    listDeviceInfo();
    FT_HANDLE device = openDeviceBySerialNumber("000000000001");

    writeToPipe(device,0x02,0x69);

    readFromPipe(device,0x82);
    closeDevice(device);
    return 0;

}