#include "src/UMFT601X.h"
#define BUFFER_ZIZE 32
int main() {

    listDeviceInfo();
    //Otwarcie urządzenia
    FT_HANDLE device;
    openDeviceBySerialNumber("000000000001",&device);

    //Napisanie bajta do pipe 0x2
    writeToPipe(device,0x02,0x69);
    
    //Napisanie buforu BUFFER_ZIZE bajtowego do pipe 0x2
    
    UCHAR buffer[BUFFER_ZIZE-1] = {0xFF};
    writeBufferToPipe(device,0x02,buffer,BUFFER_ZIZE);

    //Zczytanie bajta z pipe 0x82
    unsigned char dane;
    readFromPipe(device,0x82,&dane);

    //Zamknięcie urządzenia
    closeDevice(device);
    return 0;

}