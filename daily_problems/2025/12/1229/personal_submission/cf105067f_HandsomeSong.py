import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,l,r=MII()
a=LII()
low=17
k=[0]*low
for v in a:
    for b in range(low):
        if v>>b&1:
            k[b]+=1
sm={0}
for b in range(low):
    c0=k[b]<<b
    c1=(n-k[b])<<b
    new=set()
    for s in sm:
        new.add(s+c0)
        new.add(s+c1)
    sm=new
ans=0
x=n<<low
for s in sm:
    if s>r:
        continue
    ll=max(0,-(-(l-s)//x))
    hh=(r-s)//x
    if hh>=ll:
        ans+=hh-ll+1
print(ans)