class UnionFind:
    def __init__(self,n):
        self.parent=list(range(n))
        self.size=[1]*n
        self.history=[]
    def find(self,x):
        while self.parent[x]!=x:
            x=self.parent[x]
        return x
    def merge(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            self.history.append((-1, -1, -1))
            return False
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.history.append((b, self.parent[b], self.size[a]))
        self.parent[b] = a
        self.size[a] += self.size[b]
        return True
    def back(self,steps):
        for _ in range(steps):
            b,old_parent_b,old_size_a=self.history.pop()
            if b==-1:
                continue
            a=self.parent[b]
            self.parent[b]=old_parent_b
            self.size[a]=old_size_a
def MII():
    return map(int, input().split())
n, m = MII()
dsu = UnionFind(n * 2)
ans = 1
steps = 0
for _ in range(m):
    u, v = MII()
    u -= 1
    v -= 1
    if dsu.find(u) == dsu.find(v):
        dsu.back(steps)
        ans += 1
        steps = 0
    dsu.merge(u, v + n)
    dsu.merge(v, u + n)
    steps += 2
print(ans)