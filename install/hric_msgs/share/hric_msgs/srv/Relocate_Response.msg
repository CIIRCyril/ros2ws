
bool success #结果
uint32 error_code #错误码
string message #失败原因

#错误码
uint32 NONE=0
uint32 UNKNOWN=200
uint32 TF_ERROR=201 #TF错误
uint32 SENSOR_ERROR=202 #传感器异常
uint32 LOW_CONFIDENCE=203 #低置信度