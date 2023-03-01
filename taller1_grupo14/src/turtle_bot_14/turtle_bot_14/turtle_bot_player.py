from player_interfaces.srv import Player
from geometry_msgs.msg import Twist
import rclpy
from rclpy.node import Node
import time

class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(Player, 'turtle_bot_player_srv', self.player_callback)
        self.pub = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)
        print('---- Player Service succesfully initialized ----')
    
    def player_callback(self, request, response):
        response.respuesta = "Esta super cool"
        print(len(request.posiciones))
        tiempo = len(request.posiciones)/12600 # 315/0.025
        for i in range(len(request.posiciones)):
            self.pub.publish(request.posiciones[i])
            print(i)
            print(request.posiciones[i])
            time.sleep(tiempo)
        self.get_logger().info('Entró al servicio, y el nombre del recorrido es: '+request.nombre)
        return response


def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()