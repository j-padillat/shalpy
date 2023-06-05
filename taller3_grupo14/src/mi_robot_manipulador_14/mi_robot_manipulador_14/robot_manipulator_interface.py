import tkinter as tk
import random
from tkinter import messagebox
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import threading
from pySerialTransfer import pySerialTransfer as txfer


import rclpy
from geometry_msgs.msg import Vector3

global xrec, yrec, zrec, link, node, pub, app




class GraphApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Shalpy-Manipulador")
        self.configure(bg="orange") 
        self.x_points = []
        self.y_points = []
        self.figure = Figure(figsize=(6, 6), dpi=100)
        self.ax = self.figure.add_subplot(111)
        self.ax.set_xlabel('X')
        self.ax.set_ylabel('Y')
        self.ax.set_title('Recorrido End Effector')
        self.ax.plot([], [], 'go-')
        
        self.canvas = FigureCanvasTkAgg(self.figure, master=self)
        self.canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        self.save_button = tk.Button(self, text="Guardar", command=self.GuardarRecorrido)
        self.save_button.pack(side=tk.BOTTOM)
        self.agregarPunto(0,0)
        
    def GuardarRecorrido(self):
        file_path = tk.filedialog.asksaveasfilename(defaultextension=".png",
                                                    filetypes=(("PNG files", "*.png"), ("All files", "*.*")))
        if file_path:
            self.figure.savefig(file_path)
            messagebox.showinfo("Guardar", "La gráfica ha sido guardada correctamente.")
            
    def agregarPunto(self, xinput, yinput):
        x = xinput
        y = yinput
        self.add_point(x, y)
        
    def add_point(self, x, y):
        self.x_points.append(x)
        self.y_points.append(y)
        self.ax.plot(self.x_points, self.y_points, 'go-') 
        self.canvas.draw()

class structReception(object):
    x = 0.0
    y = 0.0
    z = 0.0
arrayChars = ''


xrec = 0.0
yrec = 0.0
app = GraphApp()

rclpy.init()
node = rclpy.create_node('robot_manipulator_interface')
pub = node.create_publisher(Vector3, '/robot_manipulator_position', 10)




def leerArduino():
    global xrec, yrec, zrec, link, node, pub, app

    print("Hilo ejecutando")
    link = txfer.SerialTransfer('/dev/ttyACM0')
    estructura2 = structReception
    while True:
        if link.available():
            print("The link is receiving")
            recSize = 0
            
            estructura2.x = link.rx_obj(obj_type='f', start_pos=recSize)
            recSize += txfer.STRUCT_FORMAT_LENGTHS['f']
            
            estructura2.y = link.rx_obj(obj_type='f', start_pos=recSize)
            recSize += txfer.STRUCT_FORMAT_LENGTHS['f']
            xrec = estructura2.x
            yrec = estructura2.y
            zrec = estructura2.z
            
            print('valores: x= {}, y= {}'.format(estructura2.x, estructura2.y))
            mensaje = Vector3()
            mensaje.x = xrec
            mensaje.y = yrec
            mensaje.z = zrec
            pub.publish(mensaje)

            app.agregarPunto(xrec, yrec)

            
        elif link.status < 0:
            if link.status == txfer.CRC_ERROR:
                print('ERROR: CRC_ERROR')
            elif link.status == txfer.PAYLOAD_ERROR:
                print('ERROR: PAYLOAD_ERROR')
            elif link.status == txfer.STOP_BYTE_ERROR:
                print('ERROR: STOP_BYTE_ERROR')
            else:
                print('ERROR: {}'.format(link.status))




def main():

    hiloRecepcion = threading.Thread(target=leerArduino)
    hiloRecepcion.start()

    
    app.mainloop()


if __name__ == '__main__':
    main()
