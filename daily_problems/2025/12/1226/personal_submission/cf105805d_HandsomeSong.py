import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
class FenwickTree:
    def __init__(self,size):
        self.n=size
        self.tree=[0]*(size+2)
    def add(self,i,val):
        while i<=self.n+1:
            self.tree[i]+=val
            i+=i&(-i)
    def query(self,i):
        s=0
        while i>0:
            s+=self.tree[i]
            i-=i&(-i)
        return s
t=II()
for _ in range(t):
    n=II()
    la=LII()
    b=[]
    ft=FenwickTree(n)
    delta=[]
    base=0
    for i in range(n):
        a=la[i]
        L=ft.query(a-1)
        E=ft.query(a)-L
        G=i-L-E
        delta.append(L-G)
        base+=G
        ft.add(a,1)
    delta.sort()
    pref=0
    ans=[str(base)]
    for d in delta:
        pref+=d
        ans.append(str(base+pref))
    print(" ".join(ans))
