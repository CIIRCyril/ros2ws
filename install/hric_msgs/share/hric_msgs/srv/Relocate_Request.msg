#匹配类型
uint8 LOCAL_MATCH = 1 #局部重定位位姿(需要提供pose_robot)
uint8 GLOBAL_MATCH = 2 #全局重定位位姿(不需要提供pose_robot，定位算法进行自动匹配)

#goal definition
geometry_msgs/PoseStamped pose_robot #机器人位姿
uint8 match_type #匹配类型
