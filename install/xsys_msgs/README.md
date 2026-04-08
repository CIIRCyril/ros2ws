# xsys System Core Service Package

xsys is a ROS 2 package that provides core system-level functionality,
primarily for retrieving device serial numbers and other essential services.

## Launch Instructions

```
# Load environment and launch system services
source install/setup.bash 
ros2 launch xsys xsys.launch.py
```

## Service Interface Documentation

### Get Device Serial Number

Retrieve the unique hardware serial number via ROS service. Interface details:

__Service Name:__ /xsys/get_serial_number
__Service Type:__ /xsys_msgs/srv/GetSerialNumber

```
string SERVICE_NAME = /xsys/get_serial_number

---
string serial_number
```

__Usage Example__

```
source install/setup.bash 
ros2 service call /xsys/get_serial_number xsys_msgs/srv/GetSerialNumber
```

__Typical Response__

```
requester: making request: xsys_msgs.srv.GetSerialNumber_Request()

response:
xsys_msgs.srv.GetSerialNumber_Response(serial_number='<serial_number>')
```
