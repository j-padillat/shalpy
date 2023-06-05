#include <Servo.h>
#include <math.h>
#include "SerialTransfer.h"

SerialTransfer myTransfer;

struct __attribute__((packed)) STRUCT_RECEPTION {
  char tecla;
  double numero1;
  double numero2;
  double numero3;
} structReception;
char arrayForReception[7];

struct __attribute__((packed)) STRUCT_POSITION {
  double x;
  double y;
} structPosition;
char arrayForTransmition[] = "hello";

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servo1_pin = 11;   // Servo 3, End effector
int servo2_pin = 9;    // Servo 1, Joint1
int servo3_pin = 10;   // Servo 2, Joint 2
int servo4_pin = 5;    // Servo 0, Base

int initial_position1 = 90;  // Servo 3
int initial_position2 = 90;  // Servo 2
int initial_position3 = 90;  // Servo 1
int initial_position4 = 90;   // Servo 0

int ang_vel = 20;   // Velocidad

int link1 = 10;        // Tamaño link 1
int link2 = 10;        // Tamaño link 2

bool punto1Mode = false; 

char tecla;
double num1;
double num2;
double num3;
char punto_string[7];

int entero1;
int entero2;
int entero3;

char key;


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
  if(myTransfer.available())
  {
    // use this variable to keep track of how many
    // bytes we've processed from the receive buffer
    uint16_t recSize = 0;

    recSize = myTransfer.rxObj(structReception, recSize);
    recSize = myTransfer.rxObj(arrayForReception, recSize);
    //String velocidad = String(structTeleop.numero);

    tecla = structReception.tecla;
    double num1 = structReception.numero1;
    double num2 = structReception.numero2;
    double num3 = structReception.numero3;
    Serial.println(tecla);
    //valor.concat(" -- ");
    //Serial.println("\n");
    //Serial.print(valor);
    //Serial.println(structTeleop.tecla);
    strcpy(punto_string, arrayForReception);
    //Serial.println(punt);
    entero1 = int(num1);
    entero2 = int(num2);
    entero3 = int(num3);
    Serial.println(String(int(num1)));
    Serial.println(String(int(num2)));
    Serial.println(String(int(num3)));
    Serial.println(punto_string);
    //Serial.println(charRecibidoEnString);
  }
  if (strcmp(punto_string, "punto1")==0) {
    punto1(tecla, entero1);
    //strcpy(punto_string, "lolxdd");
  } else if (strcmp(punto_string, "punto3")==0){
    punto3(entero1, entero2, entero3);
    strcpy(punto_string, "lolxdd");
  } else if (strcmp(punto_string, "stoppp")==0){
    punto1(tecla,entero1);
  } else if (strcmp(punto_string, "punto4")==0){
    punto4(tecla, entero1, entero2, entero3);
    strcpy(punto_string, "lolxdd");
  }


  float ang_Joint0 = initial_position4;
  float ang_Joint1 = initial_position3-180;
  float ang_Joint2 = initial_position2;
  float ang_End = initial_position1;
  float rad_ang0 = ang_Joint0 * 0.017453;
  float rad_ang1 = ang_Joint1 * 0.017453;
  float rad_ang2 = ang_Joint2 * 0.017453;
  float rad_ang3 = ang_End * 0.017453;

  float pos_X = link1 * cos(rad_ang2) + link2 * cos(rad_ang1 + rad_ang2);
  float pos_Y = link1 * sin(rad_ang2) + link2 * sin(rad_ang1 + rad_ang2);
  float pos_Z = pos_X * tan(rad_ang0);
  
  /*
  Serial.println("\n");
  Serial.print("X=");
  Serial.println(pos_X);
  Serial.print("Y=");
  Serial.println(pos_Y);
  Serial.print("Z=");
  Serial.println(pos_Z);
  */
  
  

  delay(10);
  //myTransfer.reset();
  // use this variable to keep track of how many
  // bytes we're stuffing in the transmit buffer
  structPosition.x = pos_X;
  structPosition.y = pos_Y;
  uint16_t sendSize = 0;

  ///////////////////////////////////////// Stuff buffer with struct
  sendSize = myTransfer.txObj(structPosition, sendSize);

  ///////////////////////////////////////// Stuff buffer with array
  sendSize = myTransfer.txObj(arrayForTransmition, sendSize, strlen(arrayForTransmition));

  ///////////////////////////////////////// Send buffer
  myTransfer.sendData(sendSize);
  //delay(500);

}


int c = 0;

void punto1(char key, int ang_vel) {

  if (key == 'r') {
    if (initial_position1 < 180) {
      initial_position1 += ang_vel;
      servo1.write(initial_position1);
      delay(100);
    } else{
      initial_position3 = 179;
    }
  } else if (key == 'f') {
    if (initial_position1 > 0) {
      initial_position1 += ang_vel;
      servo1.write(initial_position1);
      delay(100);
    } else{
      initial_position1 = 2;
    }
  } else if (key == 'e') {
    if (initial_position2 < 180) {
      initial_position2 += ang_vel;
      servo2.write(initial_position2);
      delay(100);
    } else{
      initial_position2 = 179;
    }
  } else if (key == 'd') {
    if (initial_position2 > 0) {
      initial_position2 += ang_vel;
      servo2.write(initial_position2);
      delay(100);
    } else{
      initial_position2 = 2;
    }
  } else if (key == 'w') {
    if (initial_position3 < 180) {
      initial_position3 += ang_vel;
      servo3.write(initial_position3);
      delay(100);
    } else{
      initial_position3 = 179;
    }
  } else if (key == 's') {
    if (initial_position3 > 0) {
      initial_position3 += ang_vel;
      servo3.write(initial_position3);
      delay(100);
    } else{
      initial_position3 = 2;
    }
  } else if (key == 'a') {
    if (initial_position4 < 180) {
      initial_position4 += ang_vel;
      servo4.write(initial_position4);
      delay(100);
    } else{
      initial_position4 = 179;
    }
  } else if (key == 'q') {
    if (initial_position4 > 1) {
      initial_position4 += ang_vel;
      servo4.write(initial_position4);
      delay(100);
    } else{
      initial_position4 = 2;
    }
  }
}

void punto3(int angle4, int angle2, int angle3) {

    /*
    String angles = input.substring(7);
    int comma1 = angles.indexOf(',');
    int comma2 = angles.lastIndexOf(',');

    int angle4 = angles.substring(0, comma1).toInt();
    int angle2 = angles.substring(comma1 + 1, comma2).toInt();
    int angle3 = angles.substring(comma2 + 1).toInt();
    */
    
  
  //Serial.println("---");
  //Serial.println(String(int(angle4)));
  //Serial.println(String(angle2));
  //Serial.println(String(angle3));

  servo4.write(angle4);
  servo2.write(angle2);
  servo3.write(angle3);
  
  
  
  /*
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "punto1") {
      punto1Mode = true;  
    } else if (input.startsWith("punto3,")) {
      punto1Mode = false; 

      String angles = input.substring(7);
      int comma1 = angles.indexOf(',');
      int comma2 = angles.lastIndexOf(',');

      int angle4 = angles.substring(0, comma1).toInt();
      int angle2 = angles.substring(comma1 + 1, comma2).toInt();
      int angle3 = angles.substring(comma2 + 1).toInt();

      servo4.write(angle4);
      servo2.write(angle2);
      servo3.write(angle3);
    }
  }
  */
}


void punto4(char key, int angle4, int angle2, int angle3) {

    /*
    String angles = input.substring(7);
    int comma1 = angles.indexOf(',');
    int comma2 = angles.lastIndexOf(',');

    int angle4 = angles.substring(0, comma1).toInt();
    int angle2 = angles.substring(comma1 + 1, comma2).toInt();
    int angle3 = angles.substring(comma2 + 1).toInt();
    */
    
  if (c<1){
    Serial.println("---xdxddd");
  //Serial.println(String(int(angle4)));
  //Serial.println(String(angle2));
  //Serial.println(String(angle3));
  servo1.write(40);

  servo4.write(angle4);
  servo2.write(angle2);
  servo3.write(angle3);
  delay(3000);

  servo1.write(180);
  delay(3000);

  servo2.write(angle2+2);
  servo3.write(angle3+30);
  int angulos = angle4+2;
  for(int i = 0; i<10; i++){
    angulos+=i;
    servo4.write(angulos);
    Serial.println("lolxd");
    Serial.println(String(i));
    delay(700);
  }
  

  }
  
  
  c+=1;
  
  /*
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "punto1") {
      punto1Mode = true;  
    } else if (input.startsWith("punto3,")) {
      punto1Mode = false; 

      String angles = input.substring(7);
      int comma1 = angles.indexOf(',');
      int comma2 = angles.lastIndexOf(',');

      int angle4 = angles.substring(0, comma1).toInt();
      int angle2 = angles.substring(comma1 + 1, comma2).toInt();
      int angle3 = angles.substring(comma2 + 1).toInt();

      servo4.write(angle4);
      servo2.write(angle2);
      servo3.write(angle3);
    }
  }
  */
}
