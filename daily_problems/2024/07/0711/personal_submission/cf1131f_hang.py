class UF:
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n))
        self.k = [[i] for i in range(n)]
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if len(self.k[x]) > len(self.k[y]):
            x,y = y,x
        while self.k[x]:
            self.k[y].append(self.k[x].pop())
        self.parent[x] = y
    
def main():
    n = int(input())
    uf = UF(n)
    for _ in range(n-1):
        x,y = map(lambda x : int(x) - 1, input().split())
        uf.union(x,y)
    t = uf.k[uf.find(0)]
    t = [i+1 for i in t]
    print(*t)
main()