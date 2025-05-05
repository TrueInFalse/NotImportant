
import collections

nums=[3,3,4,3,9,54,3,4,9,9,4,94,9,56,4]
n=len(nums)
idx=collections.defaultdict(int)
for i in range(n):
    idx[nums[i]]+=1
#sn=set(nums)
#m,ans=len(sn),[]
ans=[]
for i in range(n):
    if idx[nums[i]]>(n/4):
        if nums[i] not in ans:
            ans.append(nums[i])
print(sorted(ans))

'''
import collections
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param nums int整型 一维数组 
# @return int整型一维数组
#
class Solution:
    def findBall(self, nums) :
        # write code here
        n,ans=len(nums),[]
        idx=collections.defaultdict(int)
        for i in range(n):
            idx[nums[i]]+=1
        for i in range(n):
            if idx[nums[i]]>=(n/4):
                if nums[i] not in ans:
                    ans.append(nums[i])
        return sorted(ans)
'''