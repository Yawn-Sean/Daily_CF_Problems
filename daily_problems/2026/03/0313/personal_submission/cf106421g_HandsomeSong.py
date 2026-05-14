import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
class FenwickTree:
    def __init__(self,n):
        self.n=n
        self.tree=[0]*(n+1)
    def add(self,idx,val):
        while idx<=self.n:
            self.tree[idx]+=val
            idx+=idx&(-idx)
    def query(self,idx):
        s=0
        while idx>0:
            s+=self.tree[idx]
            idx-=idx&(-idx)
        return s
def count(arr,strict):
    sorted_arr=sorted(list(set(arr)))
    rank={v:i+1 for i,v in enumerate(sorted_arr)}
    fwt=FenwickTree(len(sorted_arr))
    ans=0
    total=0
    for x in arr:
        r=rank[x]
        if strict:
            ans+=total-fwt.query(r)
        else:
            ans+=total-fwt.query(r-1)
        fwt.add(r,1)
        total+=1
    return ans
n,a,b=MII()
p=LII()
acc=[0]*(n+1)
for i in range(n):
    acc[i+1]=acc[i]+(p[i]-b)
ans=count(acc,strict=False)
for i in range(n):
    acc[i+1]=acc[i]+(p[i]-a)
ans-=count(acc,strict=True)
print(ans)