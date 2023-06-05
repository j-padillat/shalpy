#include "SerialTransfer.h"


SerialTransfer myTransfer;

struct __attribute__((packed)) STRUCT_TELEOP {
  char tecla;
  double numero;
} structTeleop;

char arrayForReception[7];

struct __attribute__((packed)) STRUCT_RECEPTION {
  char tecla;
  double numero1;
  double numero2;
  double numero3;
} structReception;

struct __attribute__((packed)) STRUCT_POSITION {
  double x;
  double y;
} structPosition;

char arrayForTransmition[] = "hello";


void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);

  structPosition.x = 7.33;
  structPosition.y = 1.23;
}


void loop()
{

  if(myTransfer.available())
  {
    // use this variable to keep track of how many
    // bytes we've processed from the receive buffer
    uint16_t recSize = 0;

    recSize = myTransfer.rxObj(structReception, recSize);
    recSize = myTransfer.rxObj(arrayForReception, recSize);
    String valor = String(structReception.numero1);
    valor.concat(" -- ");
    Serial.println("\n");
    Serial.print(valor);
    Serial.println(structReception.tecla);
    String charRecibidoEnString = String(arrayForReception);
    Serial.println(charRecibidoEnString);

    if (structTeleop.tecla=='w') {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("\n");
      Serial.println("Entro al if de recepcion");
      digitalWrite(10, HIGH);
    }
    else{
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(10, LOW);
      Serial.println("\n");
      Serial.println("Entro al else de recepcion");
    }
  }

  myTransfer.reset();
  // use this variable to keep track of how many
  // bytes we're stuffing in the transmit buffer
  uint16_t sendSize = 0;

  ///////////////////////////////////////// Stuff buffer with struct
  sendSize = myTransfer.txObj(structPosition, sendSize);

  ///////////////////////////////////////// Stuff buffer with array
  sendSize = myTransfer.txObj(arrayForTransmition, sendSize, strlen(arrayForTransmition));

  ///////////////////////////////////////// Send buffer
  myTransfer.sendData(sendSize);
  delay(500);

  structPosition.x += 1;
  
}