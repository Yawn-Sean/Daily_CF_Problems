import sys
input = sys.stdin.readline
from math import ceil,log
def II():
    return int(input())
n=II()
a,b=1,2
ans=1
while a+b<=n:
    a,b=b,a+b
    ans+=1
print(ans)