cmake_minimum_required(VERSION 2.8.3)
project(trajectory_planning)


find_package(OpenCV REQUIRED)
find_package(PCL 1.6 REQUIRED)
 

find_package(catkin REQUIRED COMPONENTS
  tf
  tf2
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  image_transport
  cv_bridge
)


catkin_package(
 
  CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs 
 
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

 
add_executable(
trajectory_planning_node 

src/main.cpp
 
src/running_flow.cpp

src/motion_planning.cpp

src/transformation.cpp

src/seam_location.cpp
)


target_link_libraries(
trajectory_planning_node  

${catkin_LIBRARIES}
${OpenCV_LIBS}
${PCL_LIBRARIES}
)

 
