#include <math.h>
#include <vector>
#include <Eigen/Dense>

#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Bool.h>

#include <std_msgs/Bool.h>

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>

#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>

 // 定义点云类型
typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud; 
typedef pcl::PointCloud<pcl::PointXYZRGBL> PointCloudL;  
typedef pcl::PointCloud<pcl::PointXYZ>  Cloud;
typedef pcl::PointXYZ PointType;
typedef pcl::PointCloud<pcl::Normal> Normal;


extern cv::Mat color_pic, depth_pic;
extern double camera_factor ;
extern double camera_cx ;
extern double camera_cy ;  
extern double camera_fx ;
extern double camera_fy ;

extern tf::TransformListener listener;
extern tf::TransformBroadcaster tf_broadcaster;

using namespace cv;
using namespace std;
using namespace Eigen;
 
pcl::PointXYZ camera_to_base_transform(tf::StampedTransform transform, pcl::PointXYZ Cam_Object);

pcl::PointXYZ realsense_position_acquisition(tf::StampedTransform transform);

void analyze_realsense_data(PointCloud::Ptr cloud);

void coordinate_transformation(tf::StampedTransform transform, PointCloud::Ptr camera_pointcloud, PointCloud::Ptr map_pointcloud, Cloud::Ptr cloud_ptr);

Cloud::Ptr cloud_ptr_origin_copy(Cloud::Ptr cloud_ptr_new);

Cloud::Ptr input_pointcloud_filter(int process_count, int process_count_limit, Cloud::Ptr cloud_ptr, Cloud::Ptr cloud_ptr_filter);

// Eigen::Quaterniond Transform_AngleAxisd_Quatenion(vector<Point3f> Normal_Vector);
void Transform_AngleAxisd_Quatenion(Cloud::Ptr PathPoint_Position);


void rotate_z(float x, float y, float z, float angle, float* x_output, float* y_output, float* z_output) ;
void rotate_x(float x, float y, float z, float angle, float* x_output, float* y_output, float* z_output)   ;
void rotate_y(float x, float y, float z, float angle, float* x_output, float* y_output, float* z_output)   ;

void euler_to_quaternion(float Yaw, float Pitch, float Roll, float Q[4]);
