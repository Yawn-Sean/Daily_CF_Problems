import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,x,y=MII()
dis=[]
rs=[]
for _ in range(n):
    xx,yy,r=MII()
    rs.append(r)
    dis.append(((x-xx)**2+(y-yy)**2)**0.5-r)
ans=0
cur=0
for i in sorted(range(n),key=lambda x:dis[x]):
    ans=max(ans,dis[i]-cur)
    cur+=rs[i]
print(ans)