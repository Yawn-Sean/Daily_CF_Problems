import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
xs=[]
ys=[]
for _ in range(n):
    x,y=MII()
    if x>y:
        x,y=y,x
    xs.append(x)
    ys.append(y)
ans=0
cur=0
for i in sorted(range(n),key=lambda x:-ys[x]):
    cur+=xs[i]
    ans=max(ans,min(cur,ys[i]))
print(ans)