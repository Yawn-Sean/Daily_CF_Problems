def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
inf=10**10
n=II()
x=LII()
v=LII()
low=0
high=10**9
for _ in range(100):
    m=(low+high)/2
    mxl=-float(inf)
    mnr=float(inf)
    for i in range(n):
        l=x[i]-v[i]*m
        r=x[i]+v[i]*m
        if l>mxl:
            mxl=l
        if r<mnr:
            mnr=r
    if mxl<=mnr:
        high=m
    else:
        low=m
print(high)
        