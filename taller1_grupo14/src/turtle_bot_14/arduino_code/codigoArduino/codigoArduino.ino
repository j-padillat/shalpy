int PinIN1 = 2;
int PinIN2 = 3;
int PinENA = 5;
int PinIN3 = 8;
int PinIN4 = 9;
int PinENB = 10;
String tecla;
String msg;
float lineal, angular;

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
}

void loop() {

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


void MotorAdelante(float vel)
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
void MotorAtras(float vel)
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

void MotorIzquierda(float vel)
{
  //Serial.println("Giro del Motor en sentido horario");
  int new_vel = map(vel,0,10,0,255);
  analogWrite (PinENA, new_vel);
  digitalWrite (PinIN1, LOW);
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
  digitalWrite (PinIN4, LOW);
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
