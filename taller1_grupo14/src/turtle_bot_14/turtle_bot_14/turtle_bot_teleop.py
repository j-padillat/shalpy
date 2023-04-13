import rclpy
from geometry_msgs.msg import Twist
import time
from sshkeyboard import listen_keyboard
import threading

global pub, turn, speed, node

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

def vels(speed, turn):
    return 'currently:\tspeed %s\tturn %s ' % (speed, turn)


#arduino = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0042_55736313737351818241-if00", 9600, timeout = 1)

rclpy.init()
node = rclpy.create_node('turtle_bot_teleop')
pub = node.create_publisher(Twist, '/turtlebot_cmdVel', 10)

speed = float(input("Please input the lineal speed: ")) # Init set 0.5;; From [0,10]->inArduino
turn = float(input("Please input the angular speed: ")) # Init set 1.0;; From [0,10]->inArduino

print(msg)
print(vels(speed, turn))
time.sleep(0.1)



# def get_speed():
#     return speed

# def set_speed(valor):
#     speed = valor

# def set_turn(valor):
#     global turn 
#     turn = valor

# def get_turn():
#     return turn

# def get_pub():
#     return pub

def press(key):

    global turn, speed, pub

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
        
        print("Tecla: "+ str(key))
        print("Lineal: "+ str(abs(twist.linear.x)))
        print("Angular: "+ str(abs(twist.angular.z)))
        cmd = str(key)+ "," + str(twist.linear.x) + "," + str(twist.angular.z)
        #arduino.write(cmd.encode())

        pub.publish(twist)


    elif key in speedBindings.keys():
        
        speed = speed * speedBindings[key][0]
        turn = turn * speedBindings[key][1]

        print(vels(speed, turn))

        # twist = Twist()
        # twist.linear.x = x * speed
        # twist.linear.y = y * speed
        # twist.linear.z = z * speed
        # twist.angular.x = 0.0
        # twist.angular.y = 0.0
        # twist.angular.z = th * turn
        
        # print("Tecla: "+ str(key))
        # print("Lineal: "+ str(abs(twist.linear.x)))
        # print("Angular: "+ str(abs(twist.angular.z)))
        # cmd = str(key)+ "," + str(twist.linear.x) + "," + str(twist.angular.z)
        # arduino.write(cmd.encode())



def release(key):
    global speed, turn, pub
        
    try:
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

        key="stop"
        print("Tecla: "+ str(key))
        print("Lineal: "+ str(abs(twist.linear.x)))
        print("Angular: "+ str(abs(twist.angular.z)))
        cmd = str(key)+ "," + str(twist.linear.x) + "," + str(twist.angular.z)
        #arduino.write(cmd.encode())

        pub.publish(twist)

    except Exception as e:
        print(e)





def main():
    
    #if arduino.isOpen():

    listen_keyboard(on_press=press,on_release=release,delay_second_char=0.75,delay_other_chars=0.05)
    print(type(listen_keyboard))


if __name__ == '__main__':
    main()