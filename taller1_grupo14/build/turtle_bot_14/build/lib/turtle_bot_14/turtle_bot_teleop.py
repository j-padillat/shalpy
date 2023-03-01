import rclpy
from geometry_msgs.msg import Twist
import sys
if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty

### Turtle Bot Teleop Node
# This node publishes the commands to control the TurtleBot2 using the sys library for managing inputs.


msg = "--- turtle_bot_teleop succesfully initialized ---"

moveBindings = {
    'w': (1, 0, 0, 0),  # Hacia adelante en x
    'e': (1, 0, 0, -1), # Hacia adelante girando sentido horario
    'a': (0, 0, 0, 1),  # Gira sobre su eje sentido antihorario
    'd': (0, 0, 0, -1), # Gira sobre su eje sentido horario
    'q': (1, 0, 0, 1),  # Hacia adelante girando sentido antihorario
    's': (-1, 0, 0, 0), # Hacia atras en x
    'x': (-1, 0, 0, 1), # Hacia atras girando sentido antihorario
    'z': (-1, 0, 0, -1),    # Hacia atras girando sentido horario
    'W': (1, 0, 0, 0),  # Adelante
    'E': (1, -1, 0, 0), # En diagonal arriba-derecha
    #'a': (0, 1, 0, 0),  # Solo izquierda (adelante en y)
    #'d': (0, -1, 0, 0), # Solo derecha (atras en y)
    'Q': (1, 1, 0, 0),  # En diagonal arriba-izquierda
    'S': (-1, 0, 0, 0), # Atras
    'X': (-1, -1, 0, 0),    # Diagonal abajo-derecha
    'Z': (-1, 1, 0, 0), # Diagonal abajo-izquierda
    #'t': (0, 0, 1, 0),
    #'b': (0, 0, -1, 0),
}

speedBindings = {
    'u': (1.1, 1.1),    # Le sube ambas velocidades
    'j': (.9, .9),  # Le baja ambas
    'i': (1.1, 1),  # Solo le sube lineal
    'k': (.9, 1),   # Solo le baja lineal
    'o': (1, 1.1),  # Solo le sube angular
    'l': (1, .9),   # Solo le baja angular
}


def getKey(settings):
    if sys.platform == 'win32':
        # getwch() returns a string on Windows
        key = msvcrt.getwch()
    else:
        tty.setraw(sys.stdin.fileno())
        # sys.stdin.read() returns a string on Linux
        key = sys.stdin.read(1)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)


def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)


def vels(speed, turn):
    return 'currently:\tspeed %s\tturn %s ' % (speed, turn)



def main():
    settings = saveTerminalSettings()

    rclpy.init()
    node = rclpy.create_node('turtle_bot_teleop')
    pub = node.create_publisher(Twist, '/turtlebot_cmdVel', 10)

    speed = float(input("Please input the lineal speed: ")) # Init set 0.5
    turn = float(input("Please input the angular speed: ")) # Init set 1.0

    try:
        print(msg)
        print(vels(speed, turn))
        while True:
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
            pub.publish(twist)
            
            key = getKey(settings)

            if key in moveBindings.keys():
                x = moveBindings[key][0]
                y = moveBindings[key][1]
                z = moveBindings[key][2]
                th = moveBindings[key][3]

                twist = Twist()
                twist.linear.x = x * speed
                twist.linear.y = y * speed
                twist.linear.z = z * speed
                twist.angular.x = 0.0
                twist.angular.y = 0.0
                twist.angular.z = th * turn
                pub.publish(twist)

            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
                turn = turn * speedBindings[key][1]

                print(vels(speed, turn))

                twist = Twist()
                twist.linear.x = x * speed
                twist.linear.y = y * speed
                twist.linear.z = z * speed
                twist.angular.x = 0.0
                twist.angular.y = 0.0
                twist.angular.z = th * turn
                pub.publish(twist)

            else:

                if (key == '\x03'):
                    break

    except Exception as e:
        print(e)

    restoreTerminalSettings(settings)


if __name__ == '__main__':
    main()