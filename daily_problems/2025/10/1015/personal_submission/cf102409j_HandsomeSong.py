def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,l=MII()
x=LII()
x.insert(0,0)
x.append(l)
p1=p2=0
ans=l
for i in range(2,n-1):
    while x[p1+1]<=x[i]-x[p1+1]:
        p1+=1
    while x[p2+1]-x[i]<=l-x[p2+1]:
        p2+=1
    for j in range(p1,p1+2):
        for k in range(p2,p2+2):
            mx=max(x[j],x[i]-x[j], x[k]-x[i], l-x[k])
            mn=min(x[j],x[i]-x[j], x[k]-x[i], l-x[k])
            ans=min(ans,mx-mn)
print(ans)