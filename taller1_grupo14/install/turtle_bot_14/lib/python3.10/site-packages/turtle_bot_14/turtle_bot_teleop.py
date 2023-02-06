import rclpy
from rclpy.node import Node

from std_msgs.msg import String

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3


class MinimalPublisher(Node):

    def __init__(self):
        print("nollego")
        super().__init__('turtle_bot_teleop')
        print("llego")
        self.publisher_ = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)
        arroz=""
        arroz = input("Escribe la letra: ")
        if arroz == "W":
            linearMsg = Vector3()
            angularMsg = Vector3()
            linearMsg.x=2.0
            angularMsg.x = 1.8
            msg = Twist()
            msg.linear =linearMsg
            msg.angular = angularMsg
            self.publisher_.publish(msg)
            #self.get_logger().info('Publishing: "%s"; "%s"' % msg.linear % msg.angular)

        '''
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        '''
'''
    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1
'''


def main(args=None):
    rclpy.init(args=args)
    print('Antes')
    minimal_publisher = MinimalPublisher()
    print('Despues')

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
