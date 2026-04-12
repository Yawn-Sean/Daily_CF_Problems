def II():
    return int(input())
def MII():
    return map(int, input().split())
inf=10**18
n=II()
ls=[]
rs=[]
for _ in range(n):
    l,r=MII()
    ls.append(l)
    rs.append(r)
lmx=[-inf]*n
rmn=[inf]*n
for i in range(n-1):
    lmx[i+1]=max(lmx[i],ls[i])
    rmn[i+1]=min(rmn[i],rs[i])
llmx=-inf
rrmn=inf
ans=0
for i in range(n-1,-1,-1):
    ans=max(ans,min(rrmn,rmn[i])-max(llmx,lmx[i]))
    llmx=max(llmx,ls[i])
    rrmn=min(rrmn,rs[i])
print(ans)