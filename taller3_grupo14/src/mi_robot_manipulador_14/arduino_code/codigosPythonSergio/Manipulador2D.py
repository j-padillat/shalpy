import math
import tkinter as tk
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from pySerialTransfer import pySerialTransfer as txfer
import threading
from time import sleep

link = txfer.SerialTransfer('/dev/ttyACM0')
link.open()
sleep(2)


class structForTransmition(object):
    tecla = '$'
    th0_vel = 0.0
    th1 = 0.0
    th2 = 0.0

punto = 'punto3'


def inverse_kinematics(x, y, L1, L2):
    theta0 = round(math.atan2(y, x),2)
    L = math.sqrt(x**2 + y**2)
    alpha = round(math.acos((L1**2 + L**2 - L2**2) / (2 * L1 * L)),2)
    theta1 = round(math.atan2(y, x) + alpha,2)
    theta2 = round(math.acos((L1**2 + L2**2 - L**2) / (2 * L1 * L2)),2)
    return theta0, theta1, theta2
def update_graph():
    x_input = entry_x.get()
    y_input = entry_y.get()

    if not x_input or not y_input:
        return

    x_target = float(x_input)
    y_target = float(y_input)
    ######################################################################################################################################
    ##Estos son los angulos que hay que enviar al arduino como un mensaje: "punto3, theta0, theta1, theta2"
    #######################################################################################################################################
    estructuraTransmision = structForTransmition
    theta0, theta1, theta2 = inverse_kinematics(x_target, y_target, L1, L2)
    sendSize = 0
    estructuraTransmision.th0_vel = theta0 * (180/math.pi)
    estructuraTransmision.th1 = theta1 * (180/math.pi)
    estructuraTransmision.th2 = theta2 * (180/math.pi)
    print(estructuraTransmision.th0_vel)
    print(estructuraTransmision.th1)
    print(estructuraTransmision.th2)
    sendSize = link.tx_obj(estructuraTransmision.tecla, start_pos=sendSize)
    sendSize = link.tx_obj(estructuraTransmision.th0_vel, start_pos=sendSize)
    sendSize = link.tx_obj(estructuraTransmision.th1, start_pos=sendSize)
    sendSize = link.tx_obj(estructuraTransmision.th2, start_pos=sendSize)
    sendSize = link.tx_obj(punto, start_pos=sendSize)
    link.send(sendSize)
    ########################################################################################################################################

    label_theta0['text'] = f"Theta 0: {theta0:.2f}"
    label_theta1['text'] = f"Theta 1: {theta1:.2f}"
    label_theta2['text'] = f"Theta 2: {theta2:.2f}"
    x_joint1 = L1 * math.cos(theta1)
    y_joint1 = L1 * math.sin(theta1)

    x_joint2 = x_joint1 + L2 * math.cos(theta1 + theta2)
    y_joint2 = y_joint1 + L2 * math.sin(theta1 + theta2)
    ax.clear()
    ax.set_aspect('equal')
    ax.set_xlim(-30, 30)
    ax.set_ylim(-30, 30)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_title('Manipulador Diferencial')
    ax.plot([0, x_joint1, x_target], [0, y_joint1, y_target], 'bo-')  # Links
    ax.plot(0, 0, 'ro')  # Joint1
    ax.plot(x_joint1, y_joint1, 'go')  # Joint 2
    ax.plot(x_target, y_target, 'mo')  # End Effector
    canvas.draw()
    
window = tk.Tk()
window.title("Manipulador 2D")


label_x = tk.Label(window, text="X:")
label_x.grid(row=0, column=0)
entry_x = tk.Entry(window)
entry_x.grid(row=0, column=1)

label_y = tk.Label(window, text="Y:")
label_y.grid(row=1, column=0)
entry_y = tk.Entry(window)
entry_y.grid(row=1, column=1)

# Botón para actualizar la gráfica
button_update = tk.Button(window, text="Actualizar", command=update_graph)
button_update.grid(row=2, column=0, columnspan=2)


label_theta0 = tk.Label(window, text="Theta 0:")
label_theta0.grid(row=3, column=0)

label_theta1 = tk.Label(window, text="Theta 1:")
label_theta1.grid(row=4, column=0)

label_theta2 = tk.Label(window, text="Theta 2:")
label_theta2.grid(row=5, column=0)


figure = Figure(figsize=(6, 6), dpi=100)
ax = figure.add_subplot(111)


ax.set_aspect('equal')
ax.set_xlim(-30, 30)
ax.set_ylim(-30, 30)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Manipulador Diferencial')


canvas = FigureCanvasTkAgg(figure, master=window)
canvas.get_tk_widget().grid(row=6, column=0, columnspan=2)


L1 = 10
L2 = 10


tk.mainloop()
