from tkinter import Tk, Frame,Button,Label, ttk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import numpy as np
import matplotlib.pyplot as plt


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


# plt.savefig("Fig1.jpg")


def graficar_datos():
	
	x = np.arange(-np.pi, 4*np.pi, 0.01) 	

	line, = ax.plot(x, 10*np.sin(x), 
		color ='b', linestyle='solid')
	canvas.draw()

	
	#line.set_ydata(np.sin(x)+10)

	ventana.after(100, graficar_datos) ##actualizar datos


ventana = Tk()
ventana.geometry('642x498')
ventana.wm_title('Grafica Matplotlib con Scale')


frame = Frame(ventana,  bg='black')
frame.grid(column=0,row=0)

canvas = FigureCanvasTkAgg(fig, master = frame)  # Crea el area de dibujo en Tkinter
canvas.get_tk_widget().grid(column=0, row=0, columnspan=3, padx=5, pady =5)

Button(frame, text='Grafica Datos', width = 15, bg='magenta',fg='white', command= graficar_datos).grid(column=1, row=1, pady =5)




ventana.mainloop()
