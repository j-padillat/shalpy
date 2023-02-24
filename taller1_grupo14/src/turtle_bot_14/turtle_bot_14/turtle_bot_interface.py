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

# Definition of the update function
def update(frame):
    line.set_data(x_data, y_data)
    return line,

# Definition for the button commands
def guardar_datos():
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
    cliente()


    #file3 = askopenfilename()
  ######
  ######
  ##AQUI QUEDA GUARDADO EL RECORRIDO QUE SE CARGUE
  ######
  ######
    #recorridoCargado = np.genfromtxt(file3)
    #print("NuevoArray",recorridoCargado)
    #print(recorridoCargado[0])
    #print(recorridoCargado[0][0])

def para_recorrido():
    pass
    top.destroy()
##### ----------------------------------------- #######


### Updates for the buttons

frame2 = Frame(ventana,  bg='#FF5733', width=642, height=100)
frame2.grid(row=1)


BGuardar=Button(frame2, text='Guardar Imagen', width = 15, bg='white',fg='black', command= guardar_datos)
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
top.geometry("300x250")
top.title("Preguntita")
Label(top, text= "¿Desea guardar el recorrido?", font=('Mistral 11 bold')).place(x=25,y=80)
BPregunta=Button(top, text='Si', width = 15, bg='white',fg='black', command= para_recorrido)
#BPregunta.pack(side=BOTTOM)
BPregunta.grid(column=0,row=5)
BPreguntaNO=Button(top, text='No', width = 15, bg='white',fg='black', command= para_recorrido)
#BPreguntaNO.pack(side=BOTTOM)
BPreguntaNO.grid(column=1,row=5)


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


##### SUSCRIBER CALLBACK #####
def listener_callback(msg):
    #print('La posición es =  x: '+str(msg.linear.x)+'; y: ' + str(msg.linear.y)+'; Angular: ' + str(msg.angular.z))
    graficar_datos(msg.linear.x,msg.linear.y)

def velocity_callback(msg):
    linear_x.append(msg.linear.x)
    linear_y.append(msg.linear.y)
    angular_z.append(msg.angular.z)

    print(linear_x,linear_y,angular_z)

##### ----------------------------------------- #######


##### Definition of the plotting function #####
def graficar_datos(x,y):
    #     x_data.append(1,2,3)
    #     y_data.append(4,5,6)
    #     l, = ax.plot(x_data, y_data,'b.', linewidth=1)
    #     canvas.draw()
    
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
##### ----------------------------------------- #######


#### The node is initialized ####
def nodito():
    settings = saveTerminalSettings()

    rclpy.init()
    node = rclpy.create_node('turtle_bot_interface')
    node.create_subscription(Twist, '/turtlebot_position',listener_callback,10)
    node.create_subscription(Twist, '/turtlebot_cmdVel', velocity_callback ,10)

    rclpy.spin(node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()

    restoreTerminalSettings(settings)

class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('cliente_player')
        self.cli = self.create_client(Player, 'turtle_bot_player_srv')       
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = Player.Request()                                   

    def send_request(self):
        entrada = input("Introduzca el nombre del recorrido: ")
        self.req.nombre = entrada
        self.future = self.cli.call_async(self.req)

def cliente():
    client = MinimalClientAsync()
    client.send_request()

    while rclpy.ok():
        rclpy.spin_once(client)

    client.destroy_node()
    rclpy.shutdown()
##### ----------------------------------------- #######


def main():
    thread = threading.Thread(target=nodito)    # A thread is initialized to run the subscriber node
    thread.start()
    ventana.mainloop()  # The window for the interface opens



if __name__ == '__main__':
    main()