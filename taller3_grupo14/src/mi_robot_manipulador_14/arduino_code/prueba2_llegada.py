import serial

puerto_serial = '/dev/ttyUSB0'  # Cambiar al puerto serial correspondiente en tu sistema
velocidad_serial = 9600

# Crear instancia de Serial
ser = serial.Serial(puerto_serial, velocidad_serial)

string_enviado = "TextoPredefinido"  # Cambiar por el string que deseas enviar

# Enviar el string a Arduino
ser.write(string_enviado.encode())

# Cerrar el puerto serial
ser.close()
