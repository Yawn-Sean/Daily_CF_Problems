def MII():
    return map(int, input().split())
m,n=MII()
ans=0
for i in range(1,m+1):
    ans+=((i/m)**n-((i-1)/m)**n)*i
print(ans)