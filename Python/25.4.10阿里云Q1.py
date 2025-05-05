#给你一个整数，让你找出两个数a,b使得a,b异或和为x，如果有多种可能，返回max(a,b)最小的那组
def temp1(l:str,r:str):
    ans=0
    l,r='23','28'
    for i in range(int(l),int(r)+1):
        temp=oct(i)[2:]
        tmp=list(temp)
        tt=sorted(tmp)
        if tmp==tt:
            ans+=1
    return(ans)


def pro(num: int, k: int):

    res = []
    while num // k:
        t = num // k
        num = num - t * k
        res.append(t)
    res.append(num)
    res1=[str(i) for i in res]
    return ''.join(res1)

def pro(num: int, base: int) -> str:
    if num == 0:
        return '0'
    digits = '0123456789abcdefghijklmnopqrstuvwxyz'
    sign = '-' if num < 0 else ''
    num = abs(num)
    res = []
    while num > 0:
        rem = num % base
        res.append(digits[rem])
        num = num // base
    return sign + ''.join(reversed(res))

def count_non_decreasing(l: str, r: str, b: int) -> int:
    ans = 0
    for i in range(int(l), int(r) + 1):
        if b in (2, 8):
            if b == 2:
                temp = bin(i)[2:]
            elif b == 8:
                temp = oct(i)[2:]
        else:
            temp = pro(i, b)
        tmp = list(temp)
        tt = sorted(tmp)
        if tmp == tt:
            ans += 1
    return ans
