from math import inf


def plus(a: list[int], b: list[int]):
    for ii in range(len(a)):
        a[ii] = a[ii] + b[ii]
    return a


def de_plus(a: list[int], b: list[int]):
    for ii in range(len(a)):
        a[ii] = a[ii] - b[ii]
    return a


#i, j = map(int, input().split())
#i, j = 3, 2
#i, j = 1, 2
#nums = []
#nums = [[1, 0, 1, 0], [0, 1, 0, 1], [1, 1, 0, 0], [0, 0, 1, 1]]
#nums = [[1, 0], [0, 1], [1, 1]]

#nums = [[1, 1]]
i, j = 5, 3
nums=[[1,0,0],[0,1,0],[0,0,1],[0,1,0],[1,1,0]]

'''
for _ in range(i):
    temp = list(map(int, input().split()))
    nums.append(temp)
    #print(nums)
    #可以正常输出nums矩阵
'''
left = 0
ans = inf
temp1 = []
for right, num in enumerate(nums):
    if not temp1:
        temp1 = num.copy()
    else:
        #temp1 = plus(temp1, num)
        for xx in range(len(temp1)):
            temp1[xx] = temp1[xx] + num[xx]

    while 0 not in set(temp1):
        ans = min(ans, right - left + 1)
        #temp1 = de_plus(temp1, nums[left])
        for xx in range(len(temp1)):
            temp1[xx] = temp1[xx] - nums[left][xx]
        left += 1
    ans = min(ans, right - left + 1)

check_sum = [0] * j
for num in nums:
    for xx in range(len(num)):
        check_sum[xx] += num[xx]
    #check_sum = plus(check_sum, num)

for num in nums:
    if sum(num) == j:
        ans = 1
if 0 in set(check_sum):
    print(-1)
elif ans == 1:
    print(1)
else:
    print(ans)


"""

# If you need to import additional packages or classes, please import here.
from math import inf


def plus(a: list[int], b: list[int]):
    for ii in range(len(a)):
        a[ii] = a[ii] + b[ii]
    return a


def de_plus(a: list[int], b: list[int]):
    for ii in range(len(a)):
        a[ii] = a[ii] - b[ii]
    return a


def func():
    # please define the python3 input here. For example: a,b = map(int, input().strip().split())
    # please finish the function body here.
    # please define the python3 output here. For example: print().
    i, j = map(int, input().split())
    nums = []
    for _ in range(i):
        temp = list(map(int, input().split()))
        nums.append(temp)
    #可以正常输出nums矩阵
    left = 0
    ans = inf
    temp1 = []
    for right, num in enumerate(nums):
        if not temp1:
            temp1 = num
        else:
            temp1 = plus(temp1, num)

        while 0 not in set(temp1):
            ans = min(ans, right - left + 1)
            temp1 = de_plus(temp1, nums[left])
            left += 1

    check_sum = [0] * j
    for num in nums:
        check_sum = plus(check_sum, num)

    if 0 in set(check_sum):
        print(-1)
    else:
        print(ans)


if __name__ == "__main__":
    func()

"""