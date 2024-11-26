class UF:
    def __init__(self,n):
        self.n = n
        self.parent = [i for i in range(n)]
    
    def find(self,x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self,x,y):
        x,y = self.find(x),self.find(y)
        if x == y: return
        self.parent[x] = y
def main():
    n,q = map(int,input().split())
    uf = UF(n)
    uf2 = UF(n)
    for _ in range(q):
        t,x,y = map(int,input().split())
        x,y = x-1,y-1
        x,y = min(x,y),max(x,y)
        if t == 1:
            uf.union(x,y)
        elif t == 2:
            while uf2.find(x) < y:
                x = uf2.find(x)
                uf2.union(x,x+1)
                uf.union(x,x+1)
        else:
            if uf.find(x) == uf.find(y):
                print('YES')
            else:
                print('NO')
main()  
