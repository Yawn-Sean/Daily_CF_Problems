import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m=MII()
nums=LII()
ans=0
for _ in range(m):
    a,b,c=MII()
    ans=max(ans,(nums[a-1]+nums[b-1])/c)
print(ans)