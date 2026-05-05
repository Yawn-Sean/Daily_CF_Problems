import sys
import bisect
input = sys.stdin.readline
from collections import defaultdict
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
class FenwickTree:
    def __init__(self,n):
        self.size=n
        self.tree=[0]*(n+1)
    def update(self,i,delta):
        i+=1
        while i<=self.size:
            self.tree[i]+=delta
            i+=i&(-i)
    def query(self,i):
        i+=1
        s=0
        while i>0:
            s+=self.tree[i]
            i-=i&(-i)
        return s
    def query_range(self,left,right):
        if left>right:
            return 0
        return self.query(right)-(self.query(left-1) if left >0 else 0)
n=II()
a=LII()
post_map=defaultdict(list)
for idx,val in enumerate(a):
    post_map[val].append(idx)
st_val=sorted(post_map.keys())
ft=FenwickTree(n)
for i in range(n):
    ft.update(i,1)
total=0
cur=0
for v in st_val:
    indices=post_map[v]
    idx=bisect.bisect_left(indices,cur)
    order=indices[idx:]+indices[:idx]
    for tar in order:
        if tar>=cur:
            total+=ft.query_range(cur,tar)
        else:
            total+=ft.query_range(cur,n-1)+ft.query_range(0,tar)
        ft.update(tar,-1)
        cur=tar
print(total)