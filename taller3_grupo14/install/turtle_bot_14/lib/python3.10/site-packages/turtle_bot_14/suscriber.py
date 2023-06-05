import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty



def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)


def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)

def listener_callback(msg):
    Node.get_logger().info('La posición es =  x: "%d"; y: "%d"', msg.linear.x, msg.linear.y)


def main():
    settings = saveTerminalSettings()

    rclpy.init()
    node = rclpy.create_node('interfaz_sub')
    sub = node.create_subscription(Twist, '/turtlebot_position',listener_callback,10)

    rclpy.spin(sub)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    sub.destroy_node()
    rclpy.shutdown()


    restoreTerminalSettings(settings)



if __name__ == '__main__':
    main()
