#include "UMFT601X.h"

int main() {

    listDeviceInfo();
    FT_HANDLE device = openDeviceBySerialNumber("000000000001");
    closeDevice(device);
    return 0;
}