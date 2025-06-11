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
    n = II()
    uf = UnionFind(26)
    s, t = I(), I()
    g = []
    for a, b in zip(s, t):
        a, b = ord(a) - ord('a'), ord(b) - ord('a')
        if uf.find(a) != uf.find(b):
            g.append([a, b])
            uf.union(a, b)
    print(len(g))
    for a, b in g:
        print(ascii_lowercase[a], ascii_lowercase[b])


T = 1
for ii in range(T):
    # print(main())
    main()
