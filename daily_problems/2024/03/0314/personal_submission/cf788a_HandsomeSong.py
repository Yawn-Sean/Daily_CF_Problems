import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
b=[abs(a[i]-a[i+1])for i in range(n-1)]
c=[b[i]*((-1)**i)for i in range(n-1)]
prefix=[0]*n
for i in range(n-1):
    prefix[i+1]=prefix[i]+c[i]
mx_sf=[0]*n
mn_sf=[0]*n
mx_sf[-1]=prefix[-1]
mn_sf[-1]=prefix[-1] 
for i in range(n-2,-1,-1):
    mx_sf[i]=max(prefix[i],mx_sf[i+1])
    mn_sf[i]=min(prefix[i],mn_sf[i+1])
mx=-10**18
for l in range(n-1):
    if l%2==0:
        cur=mx_sf[l+1]-prefix[l] 
    else:
        cur=prefix[l]-mn_sf[l+1] 
    mx=max(mx,cur)
print(mx)
