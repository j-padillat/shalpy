import rclpy
from player_interfaces.srv import Player
import sys
import numpy as np
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty

#### --- Terminal settings for IO ----------
def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)

def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
##### ----------------------------------------- #######


def turtle_bot_player_callback(request,other):
    print('El recorrido a reproducir es: '+ request.nombre)
    






def main():
    settings = saveTerminalSettings()

    rclpy.init()
    node = rclpy.create_node('turtle_bot_player')
    node.create_service(Player, 'turtle_bot_player_srv', turtle_bot_player_callback)

    rclpy.spin(node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()

    restoreTerminalSettings(settings)


if __name__ == '__main__':
    main()