import sys
import array
input=sys.stdin.readline
def LII():
    return list(map(int,input().split()))
def MII():
    return map(int,input().split())
def query(u,L,R,l,r,x):
    if r<L or R<l:
        return 0
    if mx[u]<x:
        return 0
    if l==r:
        ans=sm[u]
        sm[u]=0
        mx[u]=0
        return ans     
    mid=(l+r) >> 1
    res=query(u<<1,L,R,l,mid,x)+query(u<<1|1,L,R,mid+1,r,x)
    mx[u]=max(mx[u<<1],mx[u<<1|1])
    sm[u]=sm[u<<1]+sm[u<<1|1]
    return res
n,q=MII()
b=LII()
size=1
while size<n:
    size <<= 1
mx=array.array('q',[0])*(2*size)
sm=array.array('q',[0])*(2*size)
for i in range(n):
    mx[size+i]=b[i]
    sm[size+i]=b[i]
for i in range(size - 1,0,-1):
    mx[i]=max(mx[i<<1],mx[i<<1|1])
    sm[i]=sm[i<<1]+sm[i<<1|1]
outs=[]
for _ in range(q):
    l,r,x=MII()
    print(query(1,l,r,1,size,x))