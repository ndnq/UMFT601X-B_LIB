## Dokumentacja

### Płytka:

UMFT601X-B 32 Bit FIFO bus, FMC(Low Pin Count) connector with B version chip
Jej dokumentacja:
https://www.mouser.pl/datasheet/2/163/DS_UMFT60xx%20module%20datasheet-1078795.pdf

### Sterowniki systemowe:

https://ftdichip.com/document/installation-guides/

https://ftdichip.com/wp-content/uploads/2020/08/AN_385-FTDI-D3XX-Driver-Installation-Guide.pdf


## Funkcje

``listDeviceInfo();``

Wyświetla informacje o podłączonych urządzeniach. 

Przykładowye wyjście:

----
    
    LISTING 
    Number of devices: 1
    Device 0:
    Flags: 4
    Type: 601
    ID: 67330079
    LocId: 0
    SerialNumber: 000000000001
    Description: FTDI SuperSpeed-FIFO Bridge
    ftHandle: 0
---
``openDeviceBySerialNumber (std::string serialNumber,FT_HANDLE *ftHandle)``

Otwiera połączenia z urządzeniem z danym ```SerialNumber``` i zapisuje w zmiennej wskazanej przez ftHandle ```handle```. Zwraca FT_STATUS związany z powodzeniem operacji.


``closeDevice (FT_HANDLE ftHandle);``     

Zamyka połączenie z urządzeniem zwraca ```handle``` do niego

```writeToPipe (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char value  );```

Pisze do kanału (pipe) identyfikowanego przez ```pipeId``` bajt w zmiennej ```value```.


```readFromPipe (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char* pdata                       );```

Czyta z kanału (pipe) identyfikowanego przez ```pipeId``` bajt i zapisuje go do zmiennej wskazanej przez ```pdata```;

```writeBufferToPipe (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char* buffer,unsigned int size);```

Pisze do kanału (pipe) identyfikowanego przez ```pipeId``` dane w buforze wskazane przez ```buffer``` o wielkości ```size```.

```readBufferFromPipe (FT_HANDLE ftHandle, unsigned char pipeId, unsigned char* buffer,unsigned int size);```

Czyta z kanału (pipe) identyfikowanego przez ```pipeId``` dane i zapisuje je w buforze wskazanym przez ```buffer``` o wielkości ```size```.

    Pipe id to:
    0 0x01 OUT BULK endpoint for Session List commands
    0x81 IN INTERRUPT endpoint for Notification List commands
    1 0x02-0x05 OUT BULK endpoint for application write access
    0x82-0x85 IN BULK endpoint for application read access