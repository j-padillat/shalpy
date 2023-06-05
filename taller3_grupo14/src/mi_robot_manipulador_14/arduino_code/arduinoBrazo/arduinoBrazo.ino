#include "SerialTransfer.h"

SerialTransfer myTransfer;

#include <Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servo1_pin = 5;
int servo2_pin = 9;
int servo3_pin = 10;
int servo4_pin = 11;

float initial_position1 = 0;  //
float initial_position2 = 0;  //end effector
float initial_position3 = 90; //joint2
float initial_position4 = 0; 

float ang_Mov=30;

float a1=10;
float a2=10;



void setup() {

  Serial.begin(115200);
  myTransfer.begin(Serial);

  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);
  servo4.attach(servo4_pin);

  servo1.write(initial_position1);
  servo2.write(initial_position2);
  servo3.write(initial_position3);
  servo4.write(initial_position4);
}

void loop() {
  
  
  /**
  if (Serial.available()) {
    char key = Serial.read();
    if (key == 'w') {
      if (initial_position1 < 180) {
        initial_position1 += ang_Mov;
        servo1.write(initial_position1);
        delay(100);
      }
    } else if (key == 's') {
      if (initial_position1 > 0) {
        initial_position1 -= ang_Mov;
        servo1.write(initial_position1);
        delay(100);
      }
    } else if (key == 'a') {
      if (initial_position2 < 180) {
        initial_position2 += ang_Mov;
        servo2.write(initial_position2);
        delay(100);
      }
    } else if (key == 'd') {
      if (initial_position2 > 0) {
        initial_position2 -= ang_Mov;
        servo2.write(initial_position2);
        delay(100);
      }
    } else if (key == 'i') {
      if (initial_position3 < 180) {
        initial_position3 += ang_Mov;
        servo3.write(initial_position3);
        delay(100);
      }
    } else if (key == 'k') {
      if (initial_position3 > 0) {
        initial_position3 -= ang_Mov;
        servo3.write(initial_position3);
        delay(100);
      }
    } else if (key == 'j') {
      if (initial_position4 < 180) {
        initial_position4 += ang_Mov;
        servo4.write(initial_position4);
        delay(100);
      }
    } else if (key == 'l') {
      if (initial_position4 > 0) {
        initial_position4 -= ang_Mov;
        servo4.write(initial_position4);
        delay(100);
      }
    }
  }
  float ang_Joint0=initial_position4;
  float ang_Joint1=initial_position1;
  float ang_Joint2=initial_position3-90.0;
  float ang_End=initial_position2;
  */

  //float pos_X=a1*cos(ang_Joint1)+a2*cos(ang_Joint1+ang_Joint2);
  //float pos_Y=a1*sin(ang_Joint1)+a2*sin(ang_Joint1+ang_Joint2);
  float pos_X=3.5494;
  float pos_Y=14.6940;
  float pos_Z=12.245;

  /*
  Serial.println("X=");
  Serial.println(pos_X);
  Serial.println("Y=");
  Serial.println(pos_Y);
  delay(200);
  */


  //float valorFloat = 3.1416;
  uint8_t buffer[3 * sizeof(float)];
  if(myTransfer.available())
  {
    // send all received data back to Python

    // Copiar los bytes del float en el buffer
    memcpy(buffer, &pos_X, sizeof(float));
    memcpy(buffer+sizeof(float), &pos_Y, sizeof(float));
    memcpy(buffer+2 * sizeof(float), &pos_Z, sizeof(float));
    // Transmitir el contenido del buffer
    Serial.write(buffer, 3 * sizeof(float));

    for(uint16_t i=0; i < (3 * sizeof(float)); i++)
      myTransfer.packet.txBuff[i] = buffer[i];
    
    myTransfer.sendData(myTransfer.bytesRead);
  }
}
