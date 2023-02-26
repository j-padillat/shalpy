import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from player_interfaces.srv import Player
import sys
from tkinter import *
from tkinter.filedialog import asksaveasfilename, askopenfilename
import numpy as np
import matplotlib.pyplot as plt
import threading
#from PIL import Image, ImageDraw
#from PIL import ImageGrab
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)

### CREATION OF A FIGURE AND THE AXES PLOT OBJECT ####
print('tafueraxdxd')
fig, ax = plt.subplots(dpi=90, figsize=(7,5),facecolor='white')
ax.set_title("Pocision de Turtlebot",color='black',size=16, family="Arial")
ax.set_facecolor('white')
ax.axhline(linewidth=1, color='black')
ax.axvline(linewidth=1, color='black')
ax.set_xlabel("Eje  X", color='black')
ax.set_ylabel("Eje  Y", color='black')
ax.grid(b=True, which='minor', color='k', linestyle='-.', linewidth=0.5)
ax.minorticks_on()
ax.set_xlim([-2.5, 2.5])
ax.set_ylim([-2.5, 2.5])
ax.tick_params(direction='out', length=6, width=2, 
colors='black',
grid_color='r', grid_alpha=0.5)
# ----- Initialize the data -----
x_data, y_data = [], []
linear_x, linear_y, angular_z = [],[],[]
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
  #image1 = Image.new("RGB", (642, 800), (255, 255, 255))
  #draw = ImageDraw.Draw(image1)
  fig.update()
  fig.savefig(file)

  print('Entro a guardar')
  #plt.savefig(file)

  
def guardar_recorrido():
    file2 = asksaveasfilename(defaultextension='.txt')
    DatosVel = np.array([linear_x,linear_y,angular_z])
    np.savetxt(file2, DatosVel)
  
def cargar_recorrido():
    peticion = input("Escriba el nombre (se llama el servicio): ")
    nodoCliente.send_request(peticion)
    nodoCliente.get_logger().info('Llego al cliente después del servicio')


def boton_si():
    BanderitaGuardarDatos = True
    print(BanderitaGuardarDatos)
    top.destroy()

def boton_no():
    BanderitaGuardarDatos = False
    print(BanderitaGuardarDatos)
    top.destroy()
##### ----------------------------------------- #######


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


top= Toplevel(ventana)
#top.geometry("400x250")
top.title("Preguntita")
Label(top, text= "¿Desea guardar el recorrido?", font=('Mistral 11 bold')).grid(column=0,row=0)
#Label(top, text= "", font=('Mistral 11 bold')).grid(column=0,row=0)
BPregunta=Button(top, text='Si', width = 15, bg='white',fg='black', command= boton_si)
#BPregunta.pack(side=BOTTOM)
BPregunta.grid(column=0,row=1)
BPreguntaNO=Button(top, text='No', width = 15, bg='white',fg='black', command= boton_no)
#BPreguntaNO.pack(side=BOTTOM)
BPreguntaNO.grid(column=1,row=1)


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


##### ----------------------------------------- #######


##### Definition of the plotting function #####
def graficar_datos(x,y):
    if len(x_data) == 0:
        x_data.append(x)
        y_data.append(y)
        l, = ax.plot(x_data, y_data,'b.', linewidth=1)
        canvas.draw()
        l.remove()
        

    if (abs(x_data[-1]-x)>=0.01) or (abs(y_data[-1]-y)>=0.01):
        x_data.append(x)
        y_data.append(y)
        l, = ax.plot(x_data, y_data,'b.', linewidth=1)
        canvas.draw()
        print(len(x_data))
        l.remove()
        print('Cambió la figura')

def guardat_datos(x,y,z):
    print('No entro a guardar')
    print(BanderitaGuardarDatos)
    if BanderitaGuardarDatos:
        print('Entro a guardar')
        print(BanderitaGuardarDatos)
        linear_x.append(x)
        linear_y.append(y)
        angular_z.append(z)
##### ----------------------------------------- #######


#### CLASSES ####

class clientePlayer(Node):
    def __init__(self):
        super().__init__('cliente_player')
        self.cli = self.create_client(Player, 'turtle_bot_player_srv')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Player.Request()

    def send_request(self, nombrecito):
        self.req.nombre = nombrecito
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

class nodoQueSeSuscribe(Node):
    def __init__(self):
        super().__init__('turtle_bot_interface')
        self.nodoParaPosicion = self.create_subscription(Twist, '/turtlebot_position',self.listener_callback,10)
        self.nodoParaVelocidad = self.create_subscription(Twist, '/turtlebot_cmdVel', self.velocity_callback ,10)
    ##### SUSCRIBER CALLBACK #####
    def listener_callback(self, msg):
        #print('La posición es =  x: '+str(msg.linear.x)+'; y: ' + str(msg.linear.y)+'; Angular: ' + str(msg.angular.z))
        graficar_datos(msg.linear.x,msg.linear.y)

    def velocity_callback(self, msg):
        guardat_datos(msg.linear.x, msg.linear.y, msg.angular.z)


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
        BanderitaGuardarDatos = True
        ventana.mainloop()  # The window for the interface opens
    except KeyboardInterrupt:
        ventana.destroy()



if __name__ == '__main__':
    main()