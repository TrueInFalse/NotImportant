import collections

input=[3,4,2]
N,m,seed=input
ans=[]
for i in range(m):
    a=(359*i+199*seed)%N+1
    b=(101*i+53*seed)%N+1
    n=(13*i+277*seed)%10+1
    ans.append([min(a,b),max(a,b),n])

idx = collections.defaultdict(int)
lans = len(ans)

for i in range(lans):
    a1, b1, c1 = ans[i]
    for j in range(a1,b1+1):
        idx[j] += c1
res = 0
tmp=[0]*N

for i in range(N):
    tmp[i]= idx[i + 1] * idx[i + 1]

print(tmp)
print(sum(tmp))
#print(res%10007)


'''
import collections
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param input long长整型 一维数组 
# @return long长整型
#
class Solution:
    def homework(self, input) :
        N,m,seed=input
        ans=[]
        # write code here
        for i in range(m):
            a=(359*i+199*seed)%N+1
            b=(101*i+53*seed)%N+1
            n=(13*i+277*seed)%10+1
            ans.append([min(a,b),max(a,b),n])

        idx=collections.defaultdict(int)
        lans=len(ans)
        for i in range(lans):
            a1,b1,c1=ans[i]
            for j in range(a1,b1+1):
                idx[j]+=c1
                
        res=0
        for i in range(N):
            res+=idx[i+1]*idx[i+1]
            
        return res%10007


        

'''
