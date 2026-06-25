import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
n=II()
a=LII()
ans=0
idxs=[i for i in range(n) if a[i]]
for i in range(1,len(idxs)):
    x=idxs[i-1]
    y=idxs[i]
    if min(a[x],a[y])==1 and max(a[x],a[y]) <= 2:
        lx=idxs[i-2] if i-2>=0 else -1
        ry=idxs[i + 1] if i + 1 < len(idxs) else n
        ans+=(x-lx)*(ry-y)
        if y-x==1:
            ans-=1
print(ans)