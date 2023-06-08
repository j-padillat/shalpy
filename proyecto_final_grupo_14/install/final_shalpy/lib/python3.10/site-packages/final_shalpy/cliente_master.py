import sys

from proyecto_interfaces.srv import StartPerceptionTest
from example_interfaces.srv import Juanpaser
import rclpy
from rclpy.node import Node


class MinimalClientAsync(Node):

    def _init_(self):
        super()._init_('cliente_master')
        self.cli = self.create_client(StartPerceptionTest, '/group_14/start_perception_test_srv')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = StartPerceptionTest.Request()

    def send_request(self, empieza, banner):
        self.req.banner_a = input("Banner a: ")
        self.req.banner_b = input("Banner b: ")
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
    
def main():
    rclpy.init()

    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(sys.argv[1],int(sys.argv[2]))
    minimal_client.get_logger().info(
        'Message: ' +
        (response.answer))
    
    minimal_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()