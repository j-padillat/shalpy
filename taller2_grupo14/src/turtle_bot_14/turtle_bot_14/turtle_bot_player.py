from player_interfaces.srv import PlayerHardware
from geometry_msgs.msg import Twist
import rclpy
from rclpy.node import Node
import time

### Turtle Bot Player Node
# This node receives the request of custom type Player that includes the name of the circuit to play and an Array of the Twist messages to publish.

class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(PlayerHardware, 'turtle_bot_player_srv', self.player_callback)   # Creates service
        self.pub = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)    # Creates publisher
        print('---- Player Service succesfully initialized ----')
    
    def player_callback(self, request, response):
        
        for i in range(len(request.posiciones)-1):
            self.pub.publish(request.posiciones[i])
            print(i)
            print(request.posiciones[i])
            time.sleep(request.times[i])
        
        self.get_logger().info('El nombre del recorrido es: ' + request.nombre)
        return response


def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()