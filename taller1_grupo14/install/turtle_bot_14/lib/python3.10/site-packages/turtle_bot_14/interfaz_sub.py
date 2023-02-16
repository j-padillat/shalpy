import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
from tkinter import Tk, Frame,Button,Label, ttk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import numpy as np
import matplotlib.pyplot as plt
import threading
import time
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty



fig, ax = plt.subplots(dpi=90, figsize=(7,5),facecolor='white')
plt.title("Pocision de Turtlebot",color='black',size=16, family="Arial")

plt.xlim(-100, 100)
plt.ylim(-100, 100)
ax.set_facecolor('white')

ax.axhline(linewidth=1, color='black')
ax.axvline(linewidth=1, color='black')


ax.set_xlabel("Eje  X", color='black')
ax.set_ylabel("Eje  Y", color='black')
ax.tick_params(direction='out', length=6, width=2, 
colors='black',
grid_color='r', grid_alpha=0.5)

ventana = Tk()
ventana.geometry('642x498')
ventana.wm_title('Grafica Matplotlib con Scale')


frame = Frame(ventana,  bg='black')
frame.grid(column=0,row=0)

canvas = FigureCanvasTkAgg(fig, master = frame)  # Crea el area de dibujo en Tkinter
canvas.get_tk_widget().grid(column=0, row=0, columnspan=3, padx=5, pady =5)

coordenadas = []


def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)


def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)

def listener_callback(msg):
    #print('La posición es =  x: '+str(msg.linear.x)+'; y: ' + str(msg.linear.y))
    graficar_datos(msg.linear.x,msg.linear.y)
    #coordenadas.append([msg.linear.x,msg.linear.y])
    #print(coordenadas)
    


def graficar_datos(x,y):

	line, = ax.plot(x, y,color ='b', linestyle='solid')
	canvas.draw()

	
	#line.set_ydata(np.sin(x)+10)

	ventana.after(100, graficar_datos(x,y)) ##actualizar datos

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