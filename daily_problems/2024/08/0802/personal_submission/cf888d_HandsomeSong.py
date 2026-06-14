import sys
import math
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,k=MII()
ans=1
if k>=2:
    ans+=math.comb(n,2)
if k>=3:
    ans+=(math.comb(n,3)*2)
if k>=4:
    ans+=(math.comb(n,4)*9)
print(ans)