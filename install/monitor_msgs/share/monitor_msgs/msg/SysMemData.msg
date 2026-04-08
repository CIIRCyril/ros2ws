builtin_interfaces/Time timestamp
uint64 total # 系统总物理内存
uint64 used  # 系统总物理使用内存
uint64 free # 完全空闲的物理内存（未被任何进程/缓存使用）
uint64 shared
uint64 available # 实际可被新进程使用的内存（含可回收缓存）
uint64 buffers # 用于块设备（如磁盘）的临时缓存
uint64 cached  # 用于文件系统的页缓存（可回收）
uint64 sreclaimable
uint64 swap_total #交换分区总大小
uint64 swap_free  # 空闲交换分区大小