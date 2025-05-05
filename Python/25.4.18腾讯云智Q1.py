import collections

s=input()
ans=0
temp='ABCDEFGHIGKLMNOPQRSTUVWXYZ'
cnt=collections.defaultdict(int)
for ss in s:
    cnt[ss]+=ord(ss)

for tt in temp:
    if cnt[tt]==0:
        ans += ord(tt)
print(ans)