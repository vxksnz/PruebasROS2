#include <gtest/gtest.h>

#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

// Publica en /chatter y comprueba que un suscriptor recibe el mensaje.
TEST(Chatter, PublishAndReceive)
{
  auto node = std::make_shared<rclcpp::Node>("test_chatter");
  std::string received;
  auto sub = node->create_subscription<std_msgs::msg::String>(
    "chatter", 10,
    [&received](const std_msgs::msg::String & msg) {received = msg.data;});
  auto pub = node->create_publisher<std_msgs::msg::String>("chatter", 10);

  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);

  std_msgs::msg::String msg;
  msg.data = "Hola test";
  for (int i = 0; i < 50 && received.empty(); ++i) {
    pub->publish(msg);
    executor.spin_some(20ms);
  }
  EXPECT_EQ(received, "Hola test");
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}
