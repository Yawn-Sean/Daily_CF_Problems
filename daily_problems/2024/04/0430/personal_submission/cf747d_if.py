
def solve():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=[1 if a[0]>=0 else -1]
    pos=1 if a[0]>=0 else 0
    for i in range(1,n):
        if int(a[i]<0)^pos: b[-1]+=(2*pos-1)
        else:
            pos=1-pos
            b.append(2*pos-1)
    m=len(b)
    l=n
    for i in range(m):
        if b[i]<0:l=i;break
    r=-1
    for i in range(m-1,-1,-1):
        if b[i]<0:r=i;break
    if l>r: return 0
    c=[]
    tot=0
    for i in range(l,r+1):
        if b[i]>=0: c.append(b[i])
        tot+=abs(b[i])
    c.sort(key=lambda x: -x)
    even=2
    for i in range(len(c)):
        if tot<=k: break
        else: tot-=c[i];even+=2
    if tot>k: return -1
    tot=0
    for i in range(l,m):
        tot+=abs(b[i])
    odd=1
    for i in range(len(c)):
        if tot<=k: break
        else: tot-=c[i];odd+=2
    if tot>k: return even
    return min(even,odd)
print(solve())
