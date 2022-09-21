cmake_minimum_required(VERSION 3.5)
project(msb_control)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  ament_cmake
  rclcpp
  std_msgs
  geometry_msgs
  rclcpp_action
)

include_directories(include)

# Add executables here
add_executable(fk_demo_node src/main_node.cpp src/msbFKinDemo.cpp)
ament_target_dependencies(fk_demo_node ${THIS_PACKAGE_INCLUDE_DEPENDS})

# Install the node
install(TARGETS fk_demo_node
  DESTINATION lib/${PROJECT_NAME})

# Install the include directory in the build/share
install(DIRECTORY include
  DESTINATION share/${PROJECT_NAME})

install(DIRECTORY controllers DESTINATION share/${PROJECT_NAME})

ament_export_include_directories(include)
ament_export_libraries(${library_name})
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})

ament_package()
