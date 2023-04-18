from player_interfaces.srv import PlayerHardware
from geometry_msgs.msg import Twist
import rclpy
from rclpy.node import Node
import time
import serial

### Turtle Bot Player Node
# This node receives the request of custom type Player that includes the name of the circuit to play and an Array of the Twist messages to publish.

arduino = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0042_55736313737351818241-if00", 115200, timeout = 1)

class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(PlayerHardware, 'turtle_bot_player_srv', self.player_callback)   # Creates service
        self.pub = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)    # Creates publisher
        print('---- Player Service succesfully initialized ----')
    
    def player_callback(self, request, response):
        
        for i in range(len(request.posiciones)-1):
            
            print("Tecla: "+ str(request.keys[i]))
            print("Lineal: "+ str(abs(request.posiciones[i].linear.x)))
            print("Angular: "+ str(abs(request.posiciones[i].angular.z)))
            print("---")
            cmd = str(request.keys[i])+ "," + str(abs(request.posiciones[i].linear.x)) + "," + str(abs(request.posiciones[i].angular.z))
            arduino.write(cmd.encode())

            self.pub.publish(request.posiciones[i])
            print(request.posiciones[i])
            time.sleep(request.times[i])

        cmd = str("stop")+ "," + str(abs(0)) + "," + str(abs(0))
        arduino.write(cmd.encode())


        
        self.get_logger().info('El nombre del recorrido es: ' + request.nombre)
        return response


def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()