import collections
from typing import List

class Router:
    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.ans = collections.deque()
        # 优化1：使用集合存储已存在的数据包（元组形式）
        self.pset = set()
        # 优化2：使用字典维护计数（destination, timestamp）: count
        self.cnt = collections.defaultdict(int)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        # 优化3：使用元组存储数据包（列表不可哈希）
        ap_tuple = (source, destination, timestamp)
        if ap_tuple not in self.pset:
            # 维护队列长度
            if len(self.ans) == self.memoryLimit:
                old_packet = self.ans.popleft()
                # 优化4：删除旧数据包时同步更新集合和计数
                old_tuple = (old_packet[0], old_packet[1], old_packet[2])
                self.pset.remove(old_tuple)
                # 优化5：减少旧计数并清理无效键
                key = (old_packet[1], old_packet[2])
                self.cnt[key] -= 1
                if self.cnt[key] == 0:
                    del self.cnt[key]
            # 添加新数据包
            self.ans.append([source, destination, timestamp])  # 保持列表存储
            self.pset.add(ap_tuple)
            # 优化6：增加新计数
            key = (destination, timestamp)
            self.cnt[key] += 1
            return True
        return False

    def forwardPacket(self) -> List[int]:
        if self.ans:
            out = self.ans.popleft()
            # 优化7：删除已转发的数据包记录
            out_tuple = (out[0], out[1], out[2])
            self.pset.remove(out_tuple)
            # 优化8：更新计数
            key = (out[1], out[2])
            self.cnt[key] -= 1
            if self.cnt[key] == 0:
                del self.cnt[key]
            return out
        return []

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        # 优化9：直接通过字典查询计数（O(k)时间）
        total = 0
        for t in range(startTime, endTime + 1):
            total += self.cnt.get((destination, t), 0)
        return total








class Router:
    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.ans = collections.deque()

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        ap = [source, destination, timestamp]
        if ap not in self.ans:
            if len(self.ans) == self.memoryLimit:
                self.ans.popleft()
            self.ans.append(ap)
            return True
        else:
            return False

    def forwardPacket(self) -> List[int]:
        if self.ans:
            out = self.ans.popleft()
            return out
        else:
            return []

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        gt = 0
        for i in range(len(self.ans)):
            if self.ans[i][1] == destination and startTime <= self.ans[i][2] <= endTime:
                gt += 1
        return gt






import collections
import bisect
from typing import List


class Router:
    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit
        self.ans = collections.deque()
        self.pset = set()
        self.cnt = collections.defaultdict(int)
        # 新增：维护每个目标地址的有序时间戳列表
        self.timestamps = collections.defaultdict(list)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        ap = (source, destination, timestamp)
        if ap not in self.pset:
            if len(self.ans) == self.memoryLimit:
                # 移除旧数据包
                old = self.ans.popleft()
                old_tuple = (old[0], old[1], old[2])
                self.pset.remove(old_tuple)

                # 更新计数
                old_key = (old[1], old[2])
                self.cnt[old_key] -= 1
                if self.cnt[old_key] == 0:
                    del self.cnt[old_key]

                # 从时间戳列表中删除旧时间戳
                lst = self.timestamps[old[1]]
                idx = bisect.bisect_left(lst, old[2])
                if idx < len(lst) and lst[idx] == old[2]:
                    lst.pop(idx)

            # 添加新数据包
            self.ans.append([source, destination, timestamp])
            self.pset.add(ap)

            # 更新计数和时间戳列表
            key = (destination, timestamp)
            self.cnt[key] += 1
            bisect.insort(self.timestamps[destination], timestamp)  # 保持有序
            return True
        return False

    def forwardPacket(self) -> List[int]:
        if self.ans:
            out = self.ans.popleft()
            out_tuple = (out[0], out[1], out[2])
            self.pset.remove(out_tuple)

            # 更新计数
            key = (out[1], out[2])
            self.cnt[key] -= 1
            if self.cnt[key] == 0:
                del self.cnt[key]

            # 从时间戳列表中删除该时间戳
            lst = self.timestamps[out[1]]
            idx = bisect.bisect_left(lst, out[2])
            if idx < len(lst) and lst[idx] == out[2]:
                lst.pop(idx)

            return out
        return []

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        total = 0
        # 获取目标地址的有序时间戳列表
        lst = self.timestamps.get(destination, [])

        # 二分查找确定时间范围
        left = bisect.bisect_left(lst, startTime)
        right = bisect.bisect_right(lst, endTime)

        # 遍历实际存在的时间戳进行计数
        for t in lst[left:right]:
            total += self.cnt.get((destination, t), 0)
        return total
