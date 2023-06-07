import rclpy
from geometry_msgs.msg import Vector3
from std_msgs.msg import String
from player_interfaces.msg import Trace

import time
from pySerialTransfer import pySerialTransfer as txfer
from sshkeyboard import listen_keyboard
import threading
import serial


class structForTransmition(object):
    tecla = '_'
    th0_vel = 0.0
    th1 = 0.0
    th2 = 0.0

punto = 'punto1'

global msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, pub, sub, sub2

#arduino = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0042_55736313737351818241-if00", 9600, timeout = 1)
link = txfer.SerialTransfer('/dev/ttyACM0')     # Uno/Mega
#link = txfer.SerialTransfer('/dev/ttyUSB0')    # Nano
link.open() 
time.sleep(2) # allow some time for the Arduino to completely reset


msg = "--- robot_manipulator_teleop succesfully initialized ---"

moveBindings = {
    'q': (1,0),   # Sentido horario servo 0
    'a': (-1,0),  # Sentido antihorario servo 0
    'w': (1,1),   # Sentido horario servo 1
    's': (-1,1),  # Sentido antihorario servo 1
    'e': (1,2),   # Sentido horario servo 2
    'd': (-1,2),  # Sentido antihorario servo 2
    'r': (1,3),   # Sentido horario servo 3
    'f': (-1,3),  # Sentido antihorario servo 3
}

speedBindings = {
    'y': (1.1,0),    # Le sube la velocidad al servo 0
    'h': (.9,0),  # Le baja la velocidad al servo 0
    'u': (1.1,1),    # Le sube la velocidad al servo 0
    'j': (.9,1),  # Le baja la velocidad al servo 0
    'i': (1.1,2),    # Le sube la velocidad al servo 0
    'k': (.9,2),  # Le baja la velocidad al servo 0
    'o': (1.1,3),    # Le sube la velocidad al servo 0
    'l': (.9,3),  # Le baja la velocidad al servo 0
}

def vels(speed0, speed1, speed2, speed3):
    return 'currently:\tspeed_0 %s\tspeed_1 %s\tspeed_2 %s\tspeed_3 %s ' % (speed0, speed1, speed2, speed3)

def goal_callback():
    pass

def zone_callback():
    pass

rclpy.init()
node = rclpy.create_node('robot_manipulator_teleop')
pub = node.create_publisher(Vector3, '/robot_manipulator_position', 10)

sub = node.create_subscription(Vector3, '/robot_manipulator_goal',goal_callback, 10)
sub2 = node.create_subscription(String, '/robot_manipulator_zone',zone_callback, 10)

speed0 = float(input("Please input the speed for servomotor 0: ")) # Init set 0.5;; From [0,10]->inArduino
speed1 = float(input("Please input the speed for servomotor 1: ")) # Init set 0.5;; From [0,10]->inArduino
speed2 = float(input("Please input the speed for servomotor 2: ")) # Init set 0.5;; From [0,10]->inArduino
speed3 = float(input("Please input the speed for servomotor 3: ")) # Init set 0.5;; From [0,10]->inArduino

print(msg)
print(vels(speed0, speed1, speed2, speed3))
time.sleep(0.1)



def press(key):

    global msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, pub, sub, sub2, start_time

    if key in moveBindings.keys():
        
        start_time = time.time()

        mov = moveBindings[key][0]
        if (moveBindings[key][1]==0):
            vel = mov * speed0
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveBindings[key][1]))
            print("---")
        elif (moveBindings[key][1]==1):
            vel = mov * speed1
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveBindings[key][1]))
            print("---")
        elif (moveBindings[key][1]==2):
            vel = mov * speed2
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveBindings[key][1]))
            print("---")
        else:
            vel = mov * speed3
            print("Tecla: "+ str(key))
            print("Velocidad: "+ str(abs(vel)))
            print("Servo: "+ str(moveBindings[key][1]))
            print("---")
        
        
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

        # cmd = str(key)+ "," + str(twist.linear.x) + "," + str(twist.angular.z)
        # arduino.write(cmd.encode())


    elif key in speedBindings.keys():

        if (speedBindings[key][1]==0):
            speed0 = speed0 * speedBindings[key][0]
        elif (speedBindings[key][1]==1):
            speed1 = speed1 * speedBindings[key][0]
        elif (speedBindings[key][1]==2):
            speed2 = speed2 * speedBindings[key][0]
        else:
            speed3 = speed3 * speedBindings[key][0]
        

        print(vels(speed0, speed1, speed2, speed3))



def release(key):
    
    global msg, moveBindings, speedBindings, link, speed0, speed1, speed2, speed3, pub, sub, sub2, start_time
    
    try:
        
        end_time = time.time()
        elapsed_time = end_time - start_time

        # trace.key = str(key)
        # trace.time = elapsed_time

        # speed0 = 0
        # speed1 = 0
        # speed2 = 0
        # speed3 = 0

        mov = moveBindings[key][0]
        if (moveBindings[key][1]==0):
            vel = mov * speed0
        elif (moveBindings[key][1]==1):
            vel = mov * speed1
        elif (moveBindings[key][1]==2):
            vel = mov * speed2
        else:
            vel = mov * speed3

        vel = 0;

        keyServo = key
        punto="stoppp"
        print("Tecla: "+ str(key))
        print("Velocidad: "+ str(abs(vel)))
        print("Servo: "+ str(moveBindings[keyServo][1]))
        print("---")


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

        # arr = "stop"
        # testStruct = structEnviar
        # sendSize = 0
        # testStruct.z = "x"
        # testStruct.y += 1
        # sendSize = link.tx_obj(testStruct.z, start_pos=sendSize)
        # sendSize = link.tx_obj(testStruct.y, start_pos=sendSize)
        # sendSize = link.tx_obj(arr, start_pos=sendSize)
        
        # link.send(sendSize)

    except Exception as e:
        print(e)





def main():
    listen_keyboard(on_press=press,on_release=release,delay_second_char=0.5,delay_other_chars=0.2)



if __name__ == '__main__':
    main()
