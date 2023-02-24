
import rclpy
from rclpy.node import Node
from player_interfaces.srv import Player
import sys
import numpy as np


class MinimalService(Node):

    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(Player, 'turtle_bot_player_srv', self.turtle_bot_player_callback)       # CHANGE
        self.nombre=''

    def turtle_bot_player_callback(self, request, response):
        self.nombre = request.nombre                                                 # CHANGE
        print('El nombre del recorrido es: ' + self.nombre)


def main(args=None):
    rclpy.init(args=args)

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()

if __name__ == '__main__':
    main()