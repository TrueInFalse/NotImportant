import sys

n = int(sys.stdin.readline().strip())

for i in range(n*2):
        # 读取每一行
        ii=i+1
        if ii%2!=0:
            line = sys.stdin.readline().strip()
        # 把每一行的数字分隔后转化成int列表
            values = list(map(int, line.split()))
        else:
            a = sys.stdin.readline().strip()
            ass = list(map(int, a.split()))
            if values[0]*values[1]>=sum(ass):
                print('YES')
            else:
                print('NO')