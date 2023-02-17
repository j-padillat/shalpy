import rclpy
from geometry_msgs.msg import Twist
import sys
from tkinter import *
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import threading
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)

### CREATION OF A FIGURE AND THE ACES PLOT OBJECT ####
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
line, = ax.plot(x_data, y_data, 'b.', linewidth=1)
##### ------------------------------------------ ######


### CREATION OF THE TKINTER WINDOW ####
ventana = Tk()
ventana.geometry('642x498')
ventana.wm_title('Grafica Matplotlib con Scale')

frame = Frame(ventana,  bg='black')
frame.grid(column=0,row=0)

canvas = FigureCanvasTkAgg(fig, master = frame)  # Crea el area de dibujo en Tkinter
canvas.get_tk_widget().grid(column=0, row=0, columnspan=3, padx=5, pady =5)
##### ----------------------------------------- #######

# Definition of the update function
def update(frame):
    line.set_data(x_data, y_data)
    return line,



def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)

def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)

def listener_callback(msg):
    print('La posición es =  x: '+str(msg.linear.x)+'; y: ' + str(msg.linear.y))
    graficar_datos(msg.linear.x,msg.linear.y)


def graficar_datos(x,y):
    print('Entró xd')
    x_data.append(x)
    y_data.append(y)
    ax.plot(x_data, y_data,'b.', linewidth=1)
	#line, = ax.plot(x, y,color ='b', linestyle='solid')
    canvas.draw()
    print(len(x_data))
    #ax.plot(x, y, color ='b', linestyle='solid')
	#line.set_ydata(np.sin(x)+10)
	#ventana.after(100, graficar_datos(x,y)) ##actualizar datos



def nodito():
    settings = saveTerminalSettings()

    rclpy.init()
    node = rclpy.create_node('interfaz_sub')
    sub = node.create_subscription(Twist, '/turtlebot_position',listener_callback,10)

    rclpy.spin(node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()


    restoreTerminalSettings(settings)


def main():
    thread = threading.Thread(target=nodito)
    thread.start()

    #Button(frame, text='Grafica Datos', width = 15, bg='magenta',fg='white', command= graficar_datos).grid(column=1, row=1, pady =5)
    ventana.mainloop()




if __name__ == '__main__':
    main()


'''
class interfaz(nodo):
    init
    pub, sub
    func

main():
rclpy. inasid

shut dwon
'''