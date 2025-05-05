'''
from collections import Counter
Counter()
N=5792
m=111000
i = 1

sm=str(m)
idx=Counter(sm)
print(Counter(sm)['1'])
print(idx['1'])

while True:

    out = i * N
    out=str(out)
    if not Counter(out)['0'] + Counter(out)['1'] == len(str(out)):
        i += 1
    else:
        break
print(i)

'''

from collections import Counter


def findNum(self, N: int) -> int:
    # write code here
    i = 1
    while True:
        out = i * N
        out = str(out)
        if not Counter(out)['0'] + Counter(out)['1'] == len(out):
            i += 1
        else:
            return i


N = 5792
k = findNum(N, N)
print(k)
