import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from player_interfaces.srv import PlayerHardware
from player_interfaces.msg import Trace

import sys
from tkinter import *
from tkinter.filedialog import asksaveasfilename, askopenfilename
import numpy as np
import matplotlib.pyplot as plt
import threading

### Turtle Bot Interface Node
# This node is in charge of plotting the circuit of the robot, saving it into a figure and saving the trace in a .txt file
# It also uploads a trace from a .txt file and reproduce it inside the simulation


if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)

### CREATION OF A FIGURE AND THE AXES PLOT OBJECT ####
BanderitaGuardarDatos = True
fig, ax = plt.subplots(dpi=90, figsize=(7,5),facecolor='white')
ax.set_title("Posicion de Turtlebot",color='black',size=16)
ax.set_facecolor('white')
ax.axhline(linewidth=1, color='black')
ax.axvline(linewidth=1, color='black')
ax.set_xlabel("Eje  X", color='black')
ax.set_ylabel("Eje  Y", color='black')
ax.grid(b=True, which='minor', color='k', linestyle='-.', linewidth=0.5)
ax.minorticks_on()
ax.set_xlim([-5000, 5000])
ax.set_ylim([-5000, 5000])
ax.tick_params(direction='out', length=6, width=2, 
colors='black',
grid_color='r', grid_alpha=0.5)
# ----- Initialize the data -----
x_data, y_data = [], []
keys, linear_x, linear_y, angular_z, times= [],[],[],[],[]
line, = ax.plot(x_data, y_data, 'b.', linewidth=1)
DatosPos = np.array([[1, 2, 3, 4, 5, 6, 7, 8, 9, 10],[11, 12, 13, 14, 15, 16, 17, 18, 19, 20]])
##### ------------------------------------------ ######


### CREATION OF THE TKINTER WINDOW ####
ventana = Tk()
ventana.geometry('642x515')
ventana.wm_title('Interfaz TurtleBot')

frame = Frame(ventana,  bg='black', width=642, height=800)
frame.grid(column=0,row=0)

canvas = FigureCanvasTkAgg(fig, master = frame)  # Crea el area de dibujo en Tkinter
canvas.get_tk_widget().grid(column=0, row=0, columnspan=3, padx=7, pady =5)
##### ----------------------------------------- #######

# Definition for the button commands
def guardar_imagen():
    file = asksaveasfilename()
    fig.savefig(file)


def guardar_recorrido():
    file2 = asksaveasfilename(defaultextension='.txt')
    print(str(keys))
    DatosKeys = np.array(keys)
    DatosX = np.array(linear_x)
    DatosY = np.array(linear_y)
    DatosTH = np.array(angular_z)
    DatosTimes = np.array(times)
    
    print(type(DatosKeys))
    np.savetxt(file2, (DatosKeys, DatosX, DatosY, DatosTH, DatosTimes), delimiter=',',fmt='%s')

    #Datos = np.array([linear_x,linear_y,angular_z, times])
    #np.savetxt(file2, Datos)
    
    
  
def cargar_recorrido():
    peticion = input("Escriba el nombre del recorrido: ")
    file3 = askopenfilename()
    recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
    print(recorridoCargado)
    print(recorridoCargado[1].astype(np.float))
    linealx = recorridoCargado[1].astype(np.float)
    linealy = recorridoCargado[2].astype(np.float)
    anguloth = recorridoCargado[3].astype(np.float)
    tiempillos = recorridoCargado[4].astype(np.float)
    print(linealx)
    keysVector=[]
    timesVector=[]
    twistIndividual = Twist()
    twistVector = []
    print(len(linealx))
    for i in range(len(linealx)):
        keysVector.append(recorridoCargado[0][i])
        timesVector.append(tiempillos[i])
        if not ((linealx[i] == 0 and linealy[i] == 0) and anguloth[i] == 0):
            twistIndividual = Twist()
            twistIndividual.linear.x = linealx[i]
            twistIndividual.linear.y = linealy[i]
            twistIndividual.linear.z = 0.0
            twistIndividual.angular.x = 0.0
            twistIndividual.angular.y = 0.0
            twistIndividual.angular.z = anguloth[i]
            
            twistVector.append(twistIndividual)
    
    twistIndividual = Twist()
    twistIndividual.linear.x = 0.0
    twistIndividual.linear.y = 0.0
    twistIndividual.linear.z = 0.0
    twistIndividual.angular.x = 0.0
    twistIndividual.angular.y = 0.0
    twistIndividual.angular.z = 0.0
    twistVector.append(twistIndividual)

    print(len(twistVector))

    nodoCliente.send_request(peticion, twistVector, keysVector, timesVector)
    
    nodoCliente.get_logger().info('Llego al cliente después del servicio')


### Updates for the buttons

frame2 = Frame(ventana,  bg='#FF5733', width=642, height=100)
frame2.grid(row=1)

BGuardar=Button(frame2, text='Guardar Imagen', width = 15, bg='white',fg='black', command= guardar_imagen)
BGuardar.grid(column=1,row=0)
BGuardar.pack

BRecorrido=Button(frame2, text='Guardar Recorrido', width = 15, bg='white',fg='black', command= guardar_recorrido)
BRecorrido.grid(column=5,row=0)
BRecorrido.pack

BCargar=Button(frame2, text='Cargar Recorrido', width = 15, bg='white',fg='black', command= cargar_recorrido)
BCargar.grid(column=3,row=0)
BCargar.pack

vacio = Label(frame2, text=" ", bg='#FF5733', width=7, height=3)
vacio.grid(column=0, row=0)
vacio.pack

vacio1 = Label(frame2, text=" ", bg='#FF5733', width=5, height=3)
vacio1.grid(column=2, row=0)
vacio1.pack

vacio2 = Label(frame2, text=" ", bg='#FF5733', width=5, height=3)
vacio2.grid(column=4, row=0)
vacio2.pack

vacio3 = Label(frame2, text=" ", bg='#FF5733', width=6, height=3)
vacio3.grid(column=6, row=0)
vacio3.pack

##### ------------------------------------------- #######


#### --- Terminal settings for IO ----------
def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)

def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
##### ----------------------------------------- #######


##### Definition of the plotting function #####
def graficar_datos(x,y):
    if len(x_data) == 0:
        x_data.append(x)
        y_data.append(y)
        l, = ax.plot(x_data, y_data,'g.', linewidth=1)
        canvas.draw()
        l.set_ydata(y_data)

    if (abs(x_data[-1]-x)>=0.01) or (abs(y_data[-1]-y)>=0.01):
        x_data.append(x)
        y_data.append(y)
        l, = ax.plot(x_data, y_data,'g.', linewidth=1)
        canvas.draw()


def guardar_datos(key,x,y,th,time):
    # letra = 0
    # print(key)
    # if key == 'w':
    #     letra = 1
    # elif key == 'a':

    keys.append(key)
    linear_x.append(x)
    linear_y.append(y)
    angular_z.append(th)
    times.append(time)

##### ----------------------------------------- #######


#### CLASSES ####

class clientePlayer(Node):
    def __init__(self):
        super().__init__('cliente_player')
        self.cli = self.create_client(PlayerHardware, 'turtle_bot_player_srv')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = PlayerHardware.Request()

    def send_request(self, nombrecito, vectorcito, teclitas, tiempitos):
        self.req.nombre = nombrecito
        self.req.posiciones = vectorcito
        self.req.keys = teclitas
        self.req.times = tiempitos
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class nodoQueSeSuscribe(Node):
    def __init__(self):
        super().__init__('turtle_bot_interface')
        self.nodoParaPosicion = self.create_subscription(Twist, '/turtlebot_position',self.listener_callback,10)
        self.nodoParaVelocidad = self.create_subscription(Trace, '/turtlebot_Trace', self.velocity_callback ,10)
    ##### SUSCRIBER CALLBACK #####
    def listener_callback(self, msg):
        #print('La posición es =  x: '+str(msg.linear.x)+'; y: ' + str(msg.linear.y)+'; Angular: ' + str(msg.angular.z))
        graficar_datos(msg.linear.x,msg.linear.y)

    def velocity_callback(self, msg):
        guardar_datos(msg.key, msg.x, msg.y, msg.th, msg.time)


############## ROS2 STUFF ###################################
rclpy.init()
termino = False

nodoSubs = nodoQueSeSuscribe()
executor_subs = rclpy.executors.MultiThreadedExecutor()
executor_subs.add_node(nodoSubs)
executor_thread = threading.Thread(target=executor_subs.spin, daemon=True)

nodoCliente = clientePlayer()
client_executor = rclpy.executors.SingleThreadedExecutor()
client_executor.add_node(nodoCliente)
client_thread = threading.Thread(target=client_executor.spin, daemon=True)
try:
    executor_thread.start()
    client_thread.start()
except KeyboardInterrupt:
    nodoSubs.get_logger().info('KeyboardInterrupt, shutting down subs.\n')
    nodoCliente.get_logger().info('KeyboardInterrupt, shutting down client.\n')
    nodoCliente.destory_node()
    nodoSubs.destory_node()
    termino = True

def main():
    if termino:    
        rclpy.shutdown()
        executor_thread.join()
        client_executor.join()
    try:
        ventana.mainloop()  # The window for the interface opens
    except KeyboardInterrupt:
        ventana.destroy()



if __name__ == '__main__':
    main()