cmake_minimum_required(VERSION 3.20)
project(pruebas_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/talker.cpp)
target_link_libraries(talker rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(listener src/listener.cpp)
target_link_libraries(listener rclcpp::rclcpp ${std_msgs_TARGETS})

install(TARGETS talker listener DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_chatter test/test_chatter.cpp)
  target_link_libraries(test_chatter rclcpp::rclcpp ${std_msgs_TARGETS})
endif()

ament_package()
