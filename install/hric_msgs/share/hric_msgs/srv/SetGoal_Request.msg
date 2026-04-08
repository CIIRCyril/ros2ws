#导航错误码
uint32 NONE=0 # 无异常
uint32 UNKNOWN=100
uint32 GOAL_OCCUPIED=101 #目标点被占用
uint32 TIMEOUT=102 #规划超时
uint32 NO_VALID_PATH=103 #无可通行路线

#目标位姿。header中frame_id用于区分目标位姿是全局位姿还是局部位姿。若frame_id为"map"为全局目标位姿，为"base_link"为相对机器人的目标位姿。
geometry_msgs/PoseStamped goal 
