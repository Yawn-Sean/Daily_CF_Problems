import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
class Top2:
    __slots__=('freq','t1v','t1c','t2v','t2c')
    def __init__(self):
        self.freq={}
        self.t1v=self.t2v=None
        self.t1c=self.t2c=0
    def add(self,v):
        self.freq[v]=c=self.freq.get(v,0) + 1
        if v==self.t1v:
            self.t1c=c
        elif v==self.t2v:
            self.t2c=c
            if self.t2c>self.t1c:
                self.t1v,self.t1c,self.t2v,self.t2c=self.t2v,self.t2c,self.t1v,self.t1c
        elif self.t2v is None or c>self.t2c:
            self.t2v,self.t2c=v,c
            if self.t2c>self.t1c:
                self.t1v,self.t1c,self.t2v,self.t2c=self.t2v,self.t2c,self.t1v,self.t1c
t=II()
for _ in range(t):
    n=II()
    a=LII()
    if n==1:
        print(0)
    else:
        pre=[]
        tp=Top2()
        for v in a:
            tp.add(v)
            pre.append((tp.t1v,tp.t1c,tp.t2v,tp.t2c))
        ts=Top2()
        ts.add(a[-1])
        ans=0
        for j in range(n-2,-1,-1):
            pv,pc,p2v,p2c=pre[j]
            if pv != ts.t1v:
                ans=max(ans,pc + ts.t1c)
            else:
                if p2v is not None: ans=max(ans,p2c + ts.t1c)
                if ts.t2v is not None: ans=max(ans,pc + ts.t2c)
            ts.add(a[j])
        print(ans)