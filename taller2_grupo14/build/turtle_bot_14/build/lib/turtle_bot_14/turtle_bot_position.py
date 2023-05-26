from player_interfaces.srv import PlayerHardware
from geometry_msgs.msg import Twist
import numpy as np
import rclpy
from rclpy.node import Node
import time
import serial

arduino = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0042_55736313737351818241-if00", 9600, timeout = 1)


def main(args=None):
    global arduino

    rclpy.init(args=args)
    node = rclpy.create_node('turtle_bot_position')
    pub = node.create_publisher(Twist, '/turtlebot_position', 10)
    #posicion inicial del robot
    x = 0
    y = 0
    theta = np.pi/2
    #geometria del robot
    rw = 3.75
    L = 25.0

    if arduino.isOpen():

        try:
            while True:
                while arduino.inWaiting()==0: pass
                if  arduino.inWaiting()>0: 
                    

                    answer=arduino.readline()
                    
                    msg = answer.decode()
                    print(answer)
                    mensaje = msg.split(",")
                    #print(mensaje)
                    print(mensaje)
                    print(len(mensaje))
                    print('---')
                    if len(mensaje) == 3:
                        tiempo_inicial = time.time()

                        mensajeL = mensaje[1].strip()
                        mensajeR = mensaje[-1].strip()
                        print(mensajeL, mensajeR)

                        if mensajeL != '':
                            v_l = (2 * np.pi * rw * float(mensajeL)) / 60
                            v_r = (2 * np.pi * rw * float(mensajeR)) / 60
                        

                        # Definimos el tiempo transcurrido (en segundos)
                        tiempo_final = time.time()
                        #dt = tiempo_final - tiempo_inicial
                        dt = 0.3

                        # Calculamos la velocidad lineal del centro del robot
                        v = (v_l + v_r) / 2
                        # Calculamos la velocidad angular del robot
                        omega = (v_r - v_l) / L

                        # Calculamos el cambio en la posición y orientación del robot
                        dx = v * np.cos(theta) * dt
                        dy = v * np.sin(theta) * dt
                        dtheta = omega * dt 

                        # Actualizamos la posición y orientación del robot
                        x += dx
                        y += dy
                        theta += dtheta


                        twist = Twist()
                        twist.linear.x = x
                        twist.linear.y = y
                        twist.linear.z = 0.0
                        twist.angular.x = 0.0
                        twist.angular.y = 0.0
                        twist.angular.z = theta

                        pub.publish(twist)
                        #time.sleep(1)
                        arduino.flushInput() #remove data after reading
        except KeyboardInterrupt:
            print("KeyboardInterrupt has been caught.")
            rclpy.shutdown()

if __name__ == '__main__':
    main()