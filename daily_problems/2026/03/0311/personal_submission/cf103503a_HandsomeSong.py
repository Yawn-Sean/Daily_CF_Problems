import bisect
import itertools
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))

n, s = MII()
a = LII()
a.sort()
sm=sum(a)
acc = list(itertools.accumulate(a, initial=0))


l,r =0,2*10**9

while l<=r:
    mid = (l+r)//2
    pos=bisect.bisect_left(a,mid)
    if sm+(mid+1)*mid//2-acc[pos]>=s:
        r=mid-1
    else:
        l=mid+1
print(l-bisect.bisect_left(a,l)+n)