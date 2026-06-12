import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
ps=[tuple(MII()) for _ in range(n)]
vis=set(ps)
ans=0
for i in range(n):
    for j in range(i):
        x1,y1=ps[i]
        x2,y2=ps[j]
        dx=x2-x1
        dy=y2-y1
        if (x1+dx-dy,y1+dx+dy) in vis and (x1-dy,y1+dx) in vis:
            ans+=1
        if (x1+dx+dy,y1+dy-dx) in vis and (x1+dy,y1-dx) in vis:
            ans+=1
print(ans//4)