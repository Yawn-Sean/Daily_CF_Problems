class UnionFind:   # 并查集模板
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):   # 找祖先
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] >= self.size[pb]:
                self.size[pa] += self.size[pb]
                self.p[pb] = pa
            else:
                self.size[pb] += self.size[pa]
                self.p[pa] = pb

def main():
    n, m = MII()
    g = [[] for _ in range(n + 1)]
    uf = UnionFind(n + 1)
    for _ in range(m):
        ai, bi, di = MII()
        uf.union(ai, bi)
        g[ai].append([bi, di])
        g[bi].append([ai, -di])
    pos = [-inf] * (n + 1)
    for i in range(1, n + 1):
        if pos[i] == -inf:
            an = uf.find(i)
            dq = deque([an])
            pos[an] = 0
            while dq:
                node = dq.popleft()
                for ne, d in g[node]:
                    if pos[ne] == -inf:
                        pos[ne] = pos[node] - d
                        dq.append(ne)
                    else:
                        if pos[ne] + d != pos[node]:
                            return 'NO'
    return 'YES'


T = II()
for ii in range(T):
    print(main())
