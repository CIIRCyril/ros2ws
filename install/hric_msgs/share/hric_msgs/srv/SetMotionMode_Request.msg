#运动模式
uint8 START=0
uint8 STOP=1
uint8 ZERO=2
uint8 STAND=3
uint8 WALK=4
uint8 RUN=5

#导航之前请求walk模式，导航结束请求stand模式
uint8 walk_mode_request #请求切换的运动模式-> 0: start, 1: stop, 2: zero, 3: stand, 4: walk, 5: run
bool is_need_swing_arm #walk是否需要摆臂
