cmake_minimum_required(VERSION 2.8.3)
project(vg_transform)

set( CMAKE_CXX_FLAGS "-std=c++11" )

find_package(OpenCV REQUIRED)
find_package(PCL 1.6 REQUIRED)
find_package( Sophus REQUIRED )

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
  ${Sophus_INCLUDE_DIRS}
)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

 
add_executable(
vg_transform_node 

src/main.cpp
 
src/algorithm.cpp

src/transformation.cpp
)


target_link_libraries(
vg_transform_node  

${catkin_LIBRARIES}
${OpenCV_LIBS}
${PCL_LIBRARIES}
${Sophus_LIBRARIES}
)

 
