from player_interfaces.srv import PlayerHardware
from geometry_msgs.msg import Twist
import rclpy
from rclpy.node import Node
import time
import serial
from pySerialTransfer import pySerialTransfer as txfer

### Turtle Bot Player Node
# This node receives the request of custom type Player that includes the name of the circuit to play and an Array of the Twist messages to publish.

moveTeleopBindings = {
    'w': (1, 0, 0, 0),  # Hacia adelante en x
    'a': (0, 0, 0, 1),  # Gira sobre su eje sentido antihorario
    'd': (0, 0, 0, -1), # Gira sobre su eje sentido horario
    's': (-1, 0, 0, 0), # Hacia atras en x
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

link = txfer.SerialTransfer('/dev/ttyACM0')     # Uno/Mega
#link = txfer.SerialTransfer('/dev/ttyUSB0')    # Nano
link.open() 
time.sleep(2) # allow some time for the Arduino to completely reset


class structForTransmition(object):
    tecla = '_'
    th0_vel = 0.0
    th1 = 0.0
    th2 = 0.0

punto = 'punto1'


class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(PlayerHardware, 'turtle_bot_player_srv', self.player_callback)   # Creates service
        self.pub = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)    # Creates publisher
        print('---- Player Service succesfully initialized ----')
    
    def player_callback(self, request, response):
        
        for i in range(len(request.posiciones)-1):

            if (request.keys[i] in moveTeleopBindings.keys()):
            
                print("Tecla: "+ str(request.keys[i]))
                print("Lineal: "+ str(abs(request.posiciones[i].linear.x)))
                print("Angular: "+ str(abs(request.posiciones[i].angular.z)))

                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = request.keys[i]
                testStruct.th0_vel = request.posiciones[i].linear.x
                testStruct.th1 = request.posiciones[i].angular.z
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                self.pub.publish(request.posiciones[i])
                print(request.posiciones[i])
                print("---")
                time.sleep(request.times[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)



            elif (request.keys[i] in moveManipulatorBindings.keys()):

                print("Tecla: "+ str(request.keys[i]))
                print("Lineal: "+ str(abs(request.posiciones[i].linear.x)))
                print("Angular: "+ str(abs(request.posiciones[i].angular.z)))

                punto = "punto1"
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = request.keys[i]
                testStruct.th0_vel = request.posiciones[i].linear.x
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                self.pub.publish(request.posiciones[i])
                print(request.posiciones[i])
                print("---")
                time.sleep(request.times[i])


                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
        
            time.sleep(2)

        
        self.get_logger().info('El nombre del recorrido es: ' + request.nombre)
        return response


def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()