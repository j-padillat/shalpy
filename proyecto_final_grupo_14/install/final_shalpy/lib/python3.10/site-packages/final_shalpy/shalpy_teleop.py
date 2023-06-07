import rclpy
from geometry_msgs.msg import Vector3
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from player_interfaces.msg import Trace

import time
from pySerialTransfer import pySerialTransfer as txfer
from sshkeyboard import listen_keyboard
import threading
import serial

global pub, turn, speed, node, start_time, end_time, elapsed_time, pub2, trace, msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, sub, sub2

link = txfer.SerialTransfer('/dev/ttyACM0')     # Uno/Mega
#link = txfer.SerialTransfer('/dev/ttyUSB0')    # Nano
link.open() 
time.sleep(2) # allow some time for the Arduino to completely reset


msg = "--- shalpy_teleop succesfully initialized ---"



class structForTransmition(object):
    tecla = '_'
    th0_vel = 0.0
    th1 = 0.0
    th2 = 0.0

punto = 'punto1'

moveTeleopBindings = {
    'w': (1, 0, 0, 0),  # Hacia adelante en x
    'a': (0, 0, 0, 1),  # Gira sobre su eje sentido antihorario
    'd': (0, 0, 0, -1), # Gira sobre su eje sentido horario
    's': (-1, 0, 0, 0), # Hacia atras en x
}

speedTeleopBindings = {
    'z': (1.1, 1.1),    # Le sube ambas velocidades
    'x': (.9, .9),  # Le baja ambas
}

moveManipulatorBindings = {
    'y': (1,0),   # Sentido horario servo 0
    'h': (-1,0),  # Sentido antihorario servo 0
    'u': (1,1),   # Sentido horario servo 1
    'j': (-1,1),  # Sentido antihorario servo 1
    'i': (1,2),   # Sentido horario servo 2
    'k': (-1,2),  # Sentido antihorario servo 2
    'o': (1,3),   # Sentido horario servo 3
    'l': (-1,3),  # Sentido antihorario servo 3
}
speedManipulatorBindings = {
    'n': (1.1),    # Le sube la velocidad al servo 0
    'm': (.9),  # Le baja la velocidad al servo 0
}

def vels(tel_man, speed, turn, speed0, speed1, speed2, speed3):
    if (tel_man == True):
        return 'currently:\tspeed %s\tturn %s ' % (speed, turn)
    else:
        return 'currently:\tspeed_0: %s\tspeed_1: %s\tspeed_2: %s\tspeed_3: %s ' % (speed0, speed1, speed2, speed3)


rclpy.init()
node = rclpy.create_node('shalpy_teleop')
pub = node.create_publisher(Twist, '/turtlebot_cmdVel', 10)
pub2 = node.create_publisher(Trace, '/turtlebot_Trace', 10)

speed = float(input("Please input the lineal speed (0-10): ")) # Init set 0.5;; From [0,10]->inArduino
turn = float(input("Please input the angular speed (0-10): ")) # Init set 1.0;; From [0,10]->inArduino
speed0 = float(input("Please input the speed for servomotor 0 (0-10): ")) # Init set 0.5;; From [0,10]->inArduino
speed1 = float(input("Please input the speed for servomotor 1 (0-10): ")) # Init set 0.5;; From [0,10]->inArduino
speed2 = float(input("Please input the speed for servomotor 2 (0-10): ")) # Init set 0.5;; From [0,10]->inArduino
speed3 = float(input("Please input the speed for servomotor 3 (0-10): ")) # Init set 0.5;; From [0,10]->inArduino


print(msg)
print(vels(True, speed, turn, speed0, speed1, speed2, speed3))
print(vels(False, speed, turn, speed0, speed1, speed2, speed3))
time.sleep(0.1)

def press(key):

    #TODO
    global pub, turn, speed, node, start_time, end_time, elapsed_time, pub2, trace, msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, pub, sub, sub2, start_time

    if key in moveTeleopBindings.keys():
        
        start_time = time.time()

        x = moveTeleopBindings[key][0]
        y = moveTeleopBindings[key][1]
        z = moveTeleopBindings[key][2]
        th = moveTeleopBindings[key][3]
        twist = Twist()
        twist.linear.x = x * speed
        twist.linear.y = y * speed
        twist.linear.z = z * speed
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = th * turn

        trace = Trace()
        trace.x = x * speed
        trace.y = y * speed
        trace.th = th * turn

        
        print("Tecla: "+ str(key))
        print("Lineal: "+ str(abs(twist.linear.x)))
        print("Angular: "+ str(abs(twist.angular.z)))
        print("---")

        punto = "punto5" # corresponde al motor() del arduino
        testStruct = structForTransmition
        sendSize = 0
        testStruct.tecla = key
        testStruct.th0_vel = x * speed
        testStruct.th1 = th * turn
        sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
        sendSize = link.tx_obj(punto, start_pos=sendSize)
        link.send(sendSize)
        
        pub.publish(twist)

    elif key in moveManipulatorBindings.keys():
        start_time = time.time()
        mov = moveManipulatorBindings[key][0]


        if (moveManipulatorBindings[key][1]==0):
            vel = mov * speed0
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveManipulatorBindings[key][1]))
            print("---")
        elif (moveManipulatorBindings[key][1]==1):
            vel = mov * speed1
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveManipulatorBindings[key][1]))
            print("---")
        elif (moveManipulatorBindings[key][1]==2):
            vel = mov * speed2
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveManipulatorBindings[key][1]))
            print("---")
        else:
            vel = mov * speed3
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveManipulatorBindings[key][1]))
            print("---")


        trace = Trace()
        trace.x = vel
        trace.y = 0.0
        trace.th = 0.0
        
        punto = "punto1"
        testStruct = structForTransmition
        sendSize = 0
        testStruct.tecla = key
        testStruct.th0_vel = vel
        sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
        sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
        sendSize = link.tx_obj(punto, start_pos=sendSize)
        link.send(sendSize)


    elif key in speedTeleopBindings.keys():
        
        speed = speed * speedTeleopBindings[key][0]
        turn = turn * speedTeleopBindings[key][1]

        print(vels(True, speed, turn, speed0, speed1, speed2, speed3))
    
    elif key in speedManipulatorBindings.keys():
        if (speedManipulatorBindings[key][1]==0):
            speed0 = speed0 * speedManipulatorBindings[key][0]
        elif (speedManipulatorBindings[key][1]==1):
            speed1 = speed1 * speedManipulatorBindings[key][0]
        elif (speedManipulatorBindings[key][1]==2):
            speed2 = speed2 * speedManipulatorBindings[key][0]
        else:
            speed3 = speed3 * speedManipulatorBindings[key][0]

        print(vels(False, speed, turn, speed0, speed1, speed2, speed3))


def release(key):
    
    global pub, turn, speed, node, start_time, end_time, elapsed_time, pub2, trace, msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, pub, sub, sub2, start_time
        
    try:

        end_time = time.time()
        elapsed_time = end_time - start_time

        trace.key = str(key)
        trace.time = elapsed_time

        x = 0.0
        y = 0.0
        z = 0.0
        th = 0.0

        twist = Twist()
        twist.linear.x = x * speed
        twist.linear.y = y * speed
        twist.linear.z = z * speed
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = th * turn
        if key in moveTeleopBindings.keys():
            key="v"
            print("Tecla: "+ str(key))
            print("Lineal: "+ str(abs(twist.linear.x)))
            print("Angular: "+ str(abs(twist.angular.z)))
            print("---")

            punto = "punto5" # corresponde al motor() del arduino
            testStruct = structForTransmition
            sendSize = 0
            testStruct.tecla = key
            testStruct.th0_vel = x * speed
            testStruct.th1 = th * turn
            sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
            sendSize = link.tx_obj(punto, start_pos=sendSize)
            link.send(sendSize)

            pub.publish(twist)
            pub2.publish(trace)
        
        elif key in moveManipulatorBindings.keys():
            punto = "punto1"
            testStruct = structForTransmition
            sendSize = 0
            testStruct.tecla = key
            testStruct.th0_vel = 0
            sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
            sendSize = link.tx_obj(punto, start_pos=sendSize)
            link.send(sendSize)

            pub2.publish(trace)

    except Exception as e:
        print(e)





def main():

    listen_keyboard(on_press=press,on_release=release,delay_second_char=0.5,delay_other_chars=0.2)



if __name__ == '__main__':
    main()
