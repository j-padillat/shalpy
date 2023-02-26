from player_interfaces.srv import Player
import rclpy
from rclpy.node import Node

class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(Player, 'turtle_bot_player_srv', self.player_callback)
    
    def player_callback(self, request, response):
        response.respuesta = "Esta super cool"
        self.get_logger().info('Entró al servicio, y el nombre del recorrido es: '+request.nombre)
        return response


def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()




# def player_callback(request, response):
#     print("El nombre del recorrido es: " + request.nombre)
#     response = "Paso por aqui"
#     return response


# def main():
#     rclpy.init()
#     nodo = rclpy.create_node('turtle_bot_player')
#     nodo.create_service(Player, 'turtle_bot_player_srv',player_callback)
#     rclpy.spin(nodo)
#     rclpy.shutdown(nodo)



# if __name__ == '__main__':
#     main()