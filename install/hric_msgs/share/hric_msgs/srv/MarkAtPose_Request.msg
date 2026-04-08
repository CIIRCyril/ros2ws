string name #marker名字（名字唯一，重名返回失败）
string map_id #地图id，置空默认为当前地图。
string floor #楼层名字，置空默认为当前楼层。
geometry_msgs/Pose2D pose # marker的位置,theta取值范围[-pi,pi)
