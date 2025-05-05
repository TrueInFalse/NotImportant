from math import inf
from typing import List


def calculateScore(instructions: List[str], values: List[int]) -> int:
    ans=0
    n=len(values)
    i=0
    while 0<=i<n:
        if instructions[i]=='add':
            if values[i]==inf:
                break
            ans+=values[i]
            values[i]=inf
            i += 1
        elif instructions[i]=='jump':
            i+=values[i]
    return ans

instructions1=["jump","add","add","jump","add","jump"]
values1=[2,1,3,1,-2,-3]
out=calculateScore(instructions1,values1)
print(out)