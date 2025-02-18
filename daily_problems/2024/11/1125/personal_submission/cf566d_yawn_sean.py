# Submission link: https://codeforces.com/contest/566/submission/293159640
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, a):
        a = self.parent[a]
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def merge(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb: return False
        self.parent[pb] = pa
        return True

def main():
    n, q = MII()
    dsu1 = UnionFind(n)
    dsu2 = UnionFind(n)

    outs = []
    for _ in range(q):
        t, x, y = MII()
        x -= 1
        y -= 1
        if t == 1:
            dsu1.merge(x, y)
        elif t == 2:
            while dsu2.find(x) < y:
                x = dsu2.find(x)
                dsu1.merge(x + 1, x)
                dsu2.merge(x + 1, x)
        else:
            outs.append('YES' if dsu1.find(x) == dsu1.find(y) else 'NO')

    print('\n'.join(outs))