def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m,d=MII()
a=LII()
st_range=sorted(range(n),key=lambda x:a[x])
l,r=1,n
while l<=r:
    mid=(l+r)//2
    flg=True

    for i in range(mid,n):
        if a[st_range[i]]-a[st_range[i-mid]]<=d:
            flg=False
    if flg:
        r=mid-1
    else:
        l=mid+1
print(l)
ans=[0]*n
for i in range(n):
    ans[st_range[i]]=i%l+1
print(' '.join(map(str, ans)))
