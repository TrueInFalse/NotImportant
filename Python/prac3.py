import sys
t = int(sys.stdin.readline().strip())
for i in range(t * 2):
    # 读取每一行
    ii = i + 1
    if ii % 2 != 0:
        line = sys.stdin.readline().strip()
        # 把每一行的数字分隔后转化成int列表
        n=int(line)
    else:
        a = sys.stdin.readline().strip()
        ass = list(map(int, a.split()))
        left=0
        tmp,res=ass[0],(0,0)
        for right in range(1,n):
            if ass[right]!=tmp:
                left=right
                tmp=ass[right]
            else:
                if right-left>res[1]-res[0]:
                    res=(left,right)
        print(n-res[1]+res[0]-1)