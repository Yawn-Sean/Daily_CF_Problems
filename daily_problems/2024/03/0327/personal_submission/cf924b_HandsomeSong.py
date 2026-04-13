def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
ans=-1
n,u=MII()
e=LII()
l,r=0,0
while l<n:
    while r<n and e[r]-e[l]<=u:
        r+=1
    if r-l>2:
        ans=max(ans,(e[r-1]-e[l+1])/(e[r-1]-e[l]))
    l+=1
print(ans)