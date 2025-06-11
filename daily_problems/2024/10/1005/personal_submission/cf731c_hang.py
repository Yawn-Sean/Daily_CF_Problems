
from collections import Counter
class UnionFind:
    def __init__(self,n):
        self.n = n
        self.parent = [i for i in range(n)]
    
    def find(self,x):
        if self.parent[x] == x: return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self,x,y):
        x = self.find(x)
        y = self.find(y)
        if x == y: return
        self.parent[x] = y
def main():
    n,m,k = map(int,input().split())
    c = list(map(lambda x: int(x) - 1,input().split()))
    uf = UnionFind(n)
    for _ in range(m): 
        l,r = map(lambda x: int(x) - 1,input().split())
        uf.union(l,r)
    cnts = [Counter() for _ in range(n)]
    for i in range(n):
        j = uf.find(i)
        cnts[j][c[i]] += 1
    
    ans = n
    for cnt in cnts: 
        if cnt:
            ans -= max(cnt.values())
    
    print(ans)
    


main()