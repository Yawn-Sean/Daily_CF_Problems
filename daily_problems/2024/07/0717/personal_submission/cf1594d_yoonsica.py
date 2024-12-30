import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())


class UnionFind:
    def __init__(self, n):
        self.fa = list(range(n * 2 + 1))
        self.size = [1] * (n + 1) + [0] * n
    
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
            self.fa[b] = a
            self.size[a] += self.size[b]
            self.size[b] = 0
    
    def is_same(self, x, y):
        return self.find(x) == self.find(y)


# a说b是好人，那么a和b一定是同好或同坏
# a说b是坏人，那么a和b一定一好一坏
for _ in range(RI()):
    n, m = RII()
    if m == 0:
        print(n)
    else:
        uf = UnionFind(n)  # [1,n] 表示玩家是好人 [n + 1, 2*n]表示玩家是坏人
        for _ in range(m):
            a, b, t = RS().split()
            a, b = int(a), int(b)
            if t == 'imposter':  # 坏人
                # 如果a是好人，则b是坏人
                uf.union(a, b + n)
                # 如果a是坏人，则b是好人
                uf.union(b, a + n)
            else:
                # 如果a是好人，则b是好人
                uf.union(a, b)
                uf.union(a + n, b + n)
        ans = 0
        for i in range(1, n + 1):
            if uf.is_same(i, i + n):
                print(-1)
                break
            ans += max(uf.size[uf.find(i)], uf.size[uf.find(i + n)])
            uf.size[uf.find(i)] = uf.size[uf.find(i + n)] = 0
        else:
            print(ans)