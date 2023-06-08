#include <Servo.h>
#include <math.h>
#include "SerialTransfer.h"

SerialTransfer myTransfer;

// #################################################
// Estructura del mensaje de llegada/recepcion
// #################################################
struct __attribute__((packed)) STRUCT_RECEPTION {
  char tecla;
  double numero1;
  double numero2;
  double numero3;
} structReception;
char arrayForReception[7];
// #################################################
// #################################################

// #################################################
// Estructura del mensaje de salida/transmision
// #################################################

struct __attribute__((packed)) STRUCT_POSITION {
  double x;
  double y;
} structPosition;
char arrayForTransmition[] = "hello";
// #################################################
// #################################################


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servo1_pin = 43;   // Servo 3, End effector
int servo2_pin = 41;    // Servo 1, Joint1
int servo3_pin = 42;   // Servo 2, Joint 2
int servo4_pin = 40;    // Servo 0, Base


/*
Motores ///////////////////
*/
int PinIN1 = 2;
int PinIN2 = 3;
int PinENA = 5;
int PinIN3 = 8;
int PinIN4 = 9;
int PinENB = 10;

String teclas;
String msg;
float lineal, angular;

// Motor Izquierda

const byte Encoder_C1 = 18; // Cable amarillo pin 3 digital
const byte Encoder_C2 = 14; // Cable verde al pin 4 digital
byte Encoder_C1Last;
int paso1 = 0;
boolean direccion1;
float rpm1 = 0;
unsigned long timeold1 = 0;

//Motor Derecha

const byte Encoder_C3 = 19; // Cable amarillo pin 3 digital
const byte Encoder_C4 = 15; // Cable verde al pin 4 digital
byte Encoder_C3Last;
int paso2 = 0;
boolean direccion2;
float rpm2 = 0;
unsigned long timeold2 = 0;
//////////////////////////


int initial_position1 = 90;  // Servo 3
int initial_position2 = 90;  // Servo 2
int initial_position3 = 90;  // Servo 1
int initial_position4 = 90;   // Servo 0

int ang_vel = 20;   // Velocidad

int link1 = 10;        // Tamaño link 1
int link2 = 10;        // Tamaño link 2

bool punto1Mode = false;


int entero1;
int entero2;
int entero3;

char key;

// #################################################
// Variables para leer el buffer de recepcion
// #################################################
char tecla;
double num1;
double num2;
double num3;
char punto_string[7];
// #################################################
// #################################################




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



  //Motores:  configuramos los pines como salida
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinENA, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode(PinENB, OUTPUT);
  pinMode(Encoder_C2, INPUT);
  pinMode(Encoder_C1, INPUT);
  pinMode(Encoder_C4, INPUT);
  pinMode(Encoder_C3, INPUT);
  attachInterrupt(digitalPinToInterrupt(18), calculapulso1, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(19), calculapulso2, CHANGE); 
  ////////////////////////////////////////// 
}



void loop() {
  // #################################################
  // Se lee la estructura de entrada del SerialTransfer
  // #################################################
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
    // Serial.println(tecla);
    //valor.concat(" -- ");
    //Serial.println("\n");
    //Serial.print(valor);
    //Serial.println(structTeleop.tecla);
    strcpy(punto_string, arrayForReception);
    //Serial.println(punt);
    entero1 = int(num1);
    entero2 = int(num2);
    entero3 = int(num3);
    //Serial.println(String(int(num1)));
    //Serial.println(String(int(num2)));
    //Serial.println(String(int(num3)));
    //Serial.println(punto_string);
    //Serial.println(charRecibidoEnString);
  }
  if (strcmp(punto_string, "punto1")==0) {
    punto1(tecla, entero1);
  } else if (strcmp(punto_string, "punto3")==0){
    punto3(entero1, entero2, entero3);
    strcpy(punto_string, "lolxdd");
  } else if (strcmp(punto_string, "stoppp")==0){
    punto1(tecla,entero1);
  } else if (strcmp(punto_string, "punto4")==0){
    punto4(tecla, entero1, entero2, entero3);
    strcpy(punto_string, "lolxdd");
  } else if (strcmp(punto_string, "punto5")==0){
    punto5(tecla, entero1, entero2);
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
  
  
  /**
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
  **/
}



// Punto 1 teleop teclas predefinidas
void punto1(char key, int ang_vel) {

  if (key == 'o') {
    if (initial_position1 < 180) {
      initial_position1 += ang_vel;
      servo1.write(initial_position1);
      delay(100);
    } else{
      initial_position3 = 179;
    }
  } else if (key == 'l') {
    if (initial_position1 > 0) {
      initial_position1 += ang_vel;
      servo1.write(initial_position1);
      delay(100);
    } else{
      initial_position1 = 2;
    }
  } else if (key == 'i') {
    if (initial_position2 < 180) {
      initial_position2 += ang_vel;
      servo2.write(initial_position2);
      delay(100);
    } else{
      initial_position2 = 179;
    }
  } else if (key == 'k') {
    if (initial_position2 > 0) {
      initial_position2 += ang_vel;
      servo2.write(initial_position2);
      delay(100);
    } else{
      initial_position2 = 2;
    }
  } else if (key == 'u') {
    if (initial_position3 < 180) {
      initial_position3 += ang_vel;
      servo3.write(initial_position3);
      delay(100);
    } else{
      initial_position3 = 179;
    }
  } else if (key == 'j') {
    if (initial_position3 > 0) {
      initial_position3 += ang_vel;
      servo3.write(initial_position3);
      delay(100);
    } else{
      initial_position3 = 2;
    }
  } else if (key == 'h') {
    if (initial_position4 < 180) {
      initial_position4 += ang_vel;
      servo4.write(initial_position4);
      delay(100);
    } else{
      initial_position4 = 179;
    }
  } else if (key == 'y') {
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

  servo4.write(angle4);
  servo2.write(angle2);
  servo3.write(angle3);
  
}

int c = 0;
void punto4(char key, int angle4, int angle2, int angle3) {

  if (c<1){
  //  Serial.println("---xdxddd");
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
    // Serial.println("lolxd");
    // Serial.println(String(i));
    delay(700);
  }
  }
  
  
  c+=1;
 
}

void punto5(char teclas, int lineal, int angular){
  // Serial.println("Entro punto 5");
  // Serial.println(teclas);
  // Serial.println(String(lineal));
  // Serial.println(String(angular));

  if (teclas=='w') {
    MotorAdelante(lineal);
    //Serial.println("--- Entro w");
  }
  if (teclas=='s') {
    MotorAtras(lineal);
  }
  if (teclas=='a') {
    MotorIzquierda(angular);
  }
  if (teclas=='d') {
    MotorDerecha(angular);
  }
  if (teclas=='v') {
    MotorStop(lineal);
  }
 
  if (millis() - timeold1 >= 200) {
    rpm1 = -paso1* (0.481283422459893/(millis() - timeold1)) * (5.1*60000/360);
    timeold1 = millis();
    paso1 = 0;
    }
  if (millis() - timeold2 >= 200) {
    rpm2 = paso2* (0.481283422459893/(millis() - timeold2)) * (5.1*60000/360);
    timeold2 = millis();
    paso2 = 0;
    }
  //Serial.print("Mensaje,");
  //Serial.print(rpm1);
  //Serial.print(",");
  //Serial.println(rpm2);
  //delay(10);
}

void calculapulso1()
{
  int L1state = digitalRead(Encoder_C1);
  if ((Encoder_C1Last == LOW) && L1state == HIGH)
  {
    int val1 = digitalRead(Encoder_C2);
    if (val1 == LOW && direccion1)
    {
      direccion1 = false; //Reverse
    }
    else if (val1 == HIGH && !direccion1)
    {
      direccion1 = true;  //Forward
    }
  }
  Encoder_C1Last = L1state;
  if (!direccion1)  paso1++;
  else  paso1--;
  }
  void calculapulso2()
{
  int L2state = digitalRead(Encoder_C3);
  if ((Encoder_C3Last == LOW) && L2state == HIGH)
  {
    int val2 = digitalRead(Encoder_C4);
    if (val2 == LOW && direccion2)
    {
      direccion2 = false; //Reverse
    }
    else if (val2 == HIGH && !direccion2)
    {
      direccion2 = true;  //Forward
    }
  }
  Encoder_C3Last = L2state;
  if (!direccion2)  paso2++;
  else  paso2--;
  }
void MotorAdelante(float vel)
{
  //Serial.println("Giro del Motor en sentido horario");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);

  analogWrite (PinENB, new_vel+10);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
  
}
void MotorAtras(float vel)
{
  //Serial.println("Giro del Motor en sentido antihorario");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);

  analogWrite (PinENB, new_vel);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
  
}

void MotorIzquierda(float vel)
{
  //Serial.println("Giro del Motor en sentido horario");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, HIGH);
  digitalWrite (PinIN2, LOW);

  analogWrite (PinENB, new_vel);
  digitalWrite (PinIN3, HIGH);
  digitalWrite (PinIN4, LOW);
}
void MotorDerecha(float vel)
{
  //Serial.println("Giro del Motor en sentido antihorario");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, HIGH);

  analogWrite (PinENB, new_vel);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, HIGH);
}

void MotorStop(float vel)
{
  //Serial.println("Motor Detenido");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, LOW);
  digitalWrite (PinIN2, LOW);

  analogWrite (PinENB, new_vel);
  digitalWrite (PinIN3, LOW);
  digitalWrite (PinIN4, LOW);  
}