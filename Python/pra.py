from math import inf


def compare(ss: str) -> int:
    ex = 'AcMer'
    ansss = 0
    for i in range(5):
        if ss[i] == ex[i]:
            ansss += 0
        elif abs(ord(ss[i]) - ord(ex[i])) == 32:
            ansss += 5
        elif 65 <= ord(ss[i]) <= 90 and 65 <= ord(ex[i]) <= 90:
            ansss += 5
        elif 97 <= ord(ss[i]) <= 122 and 97 <= ord(ex[i]) <= 90:
            ansss += 5
        else:
            ansss += 10
    return ansss


def check(sss: str):
    ans = inf
    n = len(sss)
    left = 0
    for right in range(4, n):
        if right - left + 1 != 5:
            break
        ans = min(ans, compare(sss[left:right + 1]))
        left += 1
    print(ans)


while True:
    s = input()
    if s == '0':
        break
    else:
        check(s)
