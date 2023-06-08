import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from proyecto_interfaces.msg import Banner
from proyecto_interfaces.srv import StartNavigationTest
from proyecto_interfaces.srv import StartPerceptionTest
from proyecto_interfaces.srv import StartManipulationTest
import threading

class Master(Node):
    def __init__(self) -> None:
        super().__init__('master')
        self.subscribers = []
        topic_names = ['vision/banner_group_'+str(i) for i in range(1, 16)]
        
        for topic in topic_names:
            subscriber = self.create_subscription(Banner, topic, self.vision_callback, 10)
            self.subscribers.append(subscriber)

        self.publisher_ = self.create_publisher(Image, '/map/camera_1', 10)

        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture(0)

        if not self.cap.isOpened():
            self.get_logger().error("Unable to open camera.")
            exit(1)

        self.timer_thread = threading.Thread(target=self.timer_callback)
        self.timer_thread.start()

        while(True):
            self.get_logger().info('Choose a group to start the test (1-15):')
            group = int(input())
            if group < 1 or group > 15:
                self.get_logger().info('Invalid group number.')
            else:
                self.get_logger().info('Choose a test to start (1-3):')
                self.get_logger().info('1. Autonomous Navigation')
                self.get_logger().info('2. Perception')
                self.get_logger().info('3. Manipulation')
                test = int(input())
                if test < 1 or test > 3:
                    self.get_logger().info('Invalid test number.')
                else:
                    if test == 1:
                        self.get_logger().info('Choose a x_coordinate to go:')
                        x_coordinate = float(input())
                        self.get_logger().info('Choose a y_coordinate to go:')
                        y_coordinate = float(input())
                        self.call_navigation_test_srv(group, x_coordinate, y_coordinate)
                    elif test == 2:
                        self.get_logger().info('Choose a banner A to find:')
                        banner_a = int(input())
                        self.get_logger().info('Choose a banner B to find:')
                        banner_b = int(input())
                        self.call_perception_test_srv(group, banner_a, banner_b)
                    elif test == 3:
                        self.get_logger().info('Choose a platform to move:')
                        platform = input()
                        self.get_logger().info('Choose a x to move:')
                        x = int(input())
                        self.call_manipulation_test_srv(group, platform, x)

    def timer_callback(self):
        while True:
            ret, frame = self.cap.read()
            if not ret:
                self.get_logger().error("Failed to capture frame from camera.")
                return
            image_msg = self.bridge.cv2_to_imgmsg(frame, "bgr8")
            self.publisher_.publish(image_msg)

    def vision_callback(self, msg):
        self.get_logger().info(f'banner: {msg.banner}, figure: {msg.figure}, word: {msg.word}, color: {msg.color}')

    def call_navigation_test_srv(self, group:int, x_coordinate: float, y_coordiante: float):
        self.navigation_client = self.create_client(StartNavigationTest, '/group_'+str(group)+'/start_navigation_test_srv')
        while not self.navigation_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.req = StartNavigationTest.Request()
        self.req.x = x_coordinate
        self.req.y = y_coordiante
        self.future = self.navigation_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
    
    def call_perception_test_srv(self, group:int, banner_a:int, banner_b:int):
        self.perception_client = self.create_client(StartPerceptionTest, '/group_'+str(group)+'/start_perception_test_srv')
        while not self.perception_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.req = StartPerceptionTest.Request()
        self.req.banner_a = banner_a
        self.req.banner_b = banner_b
        self.future = self.perception_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
    
    def call_manipulation_test_srv(self, group:int, platform:str, x:int):
        self.manipulation_client = self.create_client(StartManipulationTest, '/group_'+str(group)+'/start_manipulation_test_srv')
        while not self.manipulation_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.req = StartManipulationTest.Request()
        self.req.platform = platform
        self.req.x = x
        self.future = self.manipulation_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
        
def main(args=None):
    rclpy.init(args=args)
    master = Master()
    rclpy.spin(master)
    master.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
