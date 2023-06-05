/*
#include "SerialTransfer.h"


SerialTransfer myTransfer;

struct MiPaquete {
  String dato;
};


void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial);
  pinMode(LED_BUILTIN, OUTPUT);
  //myTransfer.rxObjStruct(MiPaquete, dato);
}


void loop()
{
  if(myTransfer.available())
  {
    // Reconstruir el paquete
    MiPaquete paquete;
    memcpy(&paquete, myTransfer.packet.rxBuff, sizeof(paquete));

    String dato = paquete.dato;
    Serial.print(dato);
    Serial.flush();

    if(dato.equals("Hello")){
      digitalWrite(LED_BUILTIN, HIGH);
    }

    
    // send all received data back to Python
    for(uint16_t i=0; i < myTransfer.bytesRead; i++){
      myTransfer.packet.txBuff[i] = myTransfer.packet.rxBuff[i];
    }
    
    myTransfer.sendData(myTransfer.bytesRead);
  }
}
*/

#include "SerialTransfer.h"


SerialTransfer myTransfer;


void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial);
}


void loop()
{
  if(myTransfer.available())
  {
    // send all received data back to Python
    for(uint16_t i=0; i < myTransfer.bytesRead; i++)
      myTransfer.packet.txBuff[i] = myTransfer.packet.rxBuff[i];
    
    myTransfer.sendData(myTransfer.bytesRead);
  }
}