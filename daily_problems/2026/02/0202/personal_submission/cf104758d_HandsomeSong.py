def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

n=II()
a=LII()
pre=a[:]
pos=a[:]
for i in range(1,n):
    pre[i]=max(pre[i-1],pre[i])
for i in range(n-2,-1,-1):
    pos[i]=max(pos[i+1],pos[i])

ans=0
cur=0
for i in range(n):
    x=min(pre[i],pos[i])-a[i]
    if x==0:
        cur=0
    else:
        cur+=x
        ans=max(cur,ans)
print(ans)