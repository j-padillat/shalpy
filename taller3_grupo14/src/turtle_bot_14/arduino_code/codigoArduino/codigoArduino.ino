int PinIN1 = 2;
int PinIN2 = 3;
int PinENA = 5;
int PinIN3 = 8;
int PinIN4 = 9;
int PinENB = 10;
String tecla;
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

void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
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
  Serial.println("Empieza");
}

void loop()
{
  
  readSerialPort();
  varvel(msg,&tecla,&lineal,&angular);
  
  if (tecla=="w") {
    MotorAdelante(lineal);
  }
  if (tecla=="s") {
    MotorAtras(lineal);
  }
  if (tecla=="a") {
    MotorIzquierda(angular);
  }
  if (tecla=="d") {
    MotorDerecha(angular);
  }
  if (tecla=="stop") {
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
  Serial.print("Mensaje,");
  Serial.print(rpm1);
  Serial.print(",");
  Serial.println(rpm2);
  delay(10);
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

  analogWrite (PinENB, new_vel);
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
 
void readSerialPort() {
  msg="";
  if (Serial.available()) {
    delay(10);
    while (Serial.available() > 0) {
      msg += (char)Serial.read();

    }
    Serial.flush();

  }

}

void varvel(String x, String* tecla, float* lineal, float* angular) {
  // Separar cadena de valores
  String values[3]; // Un arreglo para almacenar los valores separados
  int index = 0; // Un índice para recorrer el arreglo de valores
  while (x.length() > 0) {
    int commaIndex = x.indexOf(','); // Busca la posición de la coma
    if (commaIndex >= 0) { // Si se encontró una coma
      values[index] = x.substring(0, commaIndex); // Almacena el valor antes de la coma
      x = x.substring(commaIndex + 1); // Elimina el valor y la coma de la cadena
    } else { // Si no se encontró una coma
      values[index] = x; // Almacena el valor restante
      x = ""; // Establece la cadena vacía para salir del bucle
    }
    index++; // Incrementa el índice del arreglo de valores
  }
  // Enterizar los valores separados
  *tecla = values[0];
  *lineal = values[1].toFloat();
  *angular = values[2].toFloat();
}
