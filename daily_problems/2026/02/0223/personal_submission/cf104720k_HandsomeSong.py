import sys
import bisect
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
n=II()
donuts=[]
for _ in range(n):
    r,R=LII()
    donuts.append((r,R))
donuts.sort()
Rs=sorted(set(d[1] for d in donuts))
bit=[0]*(len(Rs)+1)
max_beauty=-10**30
for r,R in donuts:
    pos=bisect.bisect_right(Rs,r)
    best_val=0
    i=pos
    while i>0:
        if bit[i]>best_val:best_val=bit[i]
        i-=i&-i
    dp=R*R-2*r*r+best_val
    if dp>max_beauty:max_beauty=dp
    val=dp+R*R
    idx=bisect.bisect_left(Rs,R)+1
    i=idx
    while i<=len(Rs):
        if bit[i]<val:bit[i]=val
        i+=i&-i
print(max_beauty)
