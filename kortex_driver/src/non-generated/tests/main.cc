#include <ros/ros.h>
#include <thread>
#include <gtest/gtest.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "TestNode");
  testing::InitGoogleTest(&argc, argv);

  std::thread t([]{while(ros::ok()) ros::spin();});

  auto res = RUN_ALL_TESTS();

  ros::shutdown();
  return res;
}