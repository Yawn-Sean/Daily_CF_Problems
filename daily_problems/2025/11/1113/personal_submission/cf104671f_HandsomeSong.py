import sys
input=sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
class SegTree:
    def __init__(self,op,e,data=None):
        self.op=op
        self.e=e
        if data is None:
            self.n=0
            self.size=1
            self.log=0
            self.d=[self.e]
        else:
            self.n=len(data)
            self.log=(self.n-1).bit_length()
            self.size=1 << self.log
            self.d=[self.e]*(2*self.size)
            for i in range(self.n):
                self.d[self.size+i]=data[i]
            for i in range(self.size-1, 0,-1):
                self.d[i]=self.op(self.d[2*i], self.d[2*i+1])
    def set(self, p, x):
        p += self.size
        self.d[p]=x
        while p > 1:
            p >>= 1
            self.d[p]=self.op(self.d[2*p], self.d[2*p*1])
    def prod(self, l, r):
        if l >= r:
            return self.e
        l += self.size
        r += self.size
        sml=self.e
        smr=self.e
        while l < r:
            if l & 1:
                sml=self.op(sml, self.d[l])
                l += 1
            if r & 1:
                r-= 1
                smr=self.op(self.d[r], smr)
            l >>= 1
            r >>= 1
        return self.op(sml, smr)
n,k,q=MII()
a=LII()
t=[-1]*n
for i in range(n):
    if a[i]&k==k:
        t[i]=a[i]-k
ia=lambda x,y:x&y
seg=SegTree(ia,-1,t)
for _ in range(q):
    l,r=MII()
    l-=1
    r-=1
    print("NO"if seg.prod(l,r+1)else"YES")