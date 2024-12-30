import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

class UnionFind:
    def __init__(self, n):
        self.fa = list(range(n))
        self.a = [[_] for _ in range(n)]

    def find(self, x):
        st = []
        while self.fa[x] != x:
            st.append(x)
            x = self.fa[x]
        while st:
            self.fa[st.pop()] = x
        return x

    def union(self, x, y):
        a, b = self.find(x), self.find(y)
        if a != b:
            if len(self.a[a]) < len(self.a[b]):
                a, b = b, a
            self.fa[b] = a
            self.a[a] += self.a[b]

    def is_same(self, x, y):
        return self.find(x) == self.find(y)
    
    
n = RI()
uf = UnionFind(n + 1)
for _ in range(n - 1):
    x, y = RII()
    uf.union(x, y)
ans = uf.a[uf.find(x)]
print(' '.join(str(x) for x in ans))
