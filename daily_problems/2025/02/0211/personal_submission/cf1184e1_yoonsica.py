import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1184/E1
带权无向图，求把第1条边权最大修改成多大使得该边可能出现在最小生成树里

思路：
本题只求c1 （u1，v1，w1）
最小生成树可以用kruscal求，如果边已经在最小生成树中，那么考虑调大，调成多大才不会被替代？
如果不在树中，调小，调成多小才会出现在树中？

让第一条边尽量晚加入，忽略第一条边，然后跑kruscal，当u1,v1联通时的边权就是答案。
特殊情况，如果c1本来就在最小生成树，那就改成最大值

本题用元组存边会mle
'''

class UnionFind:
    def __init__(self, n):
        self.fa = list(range(n))

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
            self.fa[a] = b

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

n, m = RII()
us, vs, ws = [], [], []
u1 = v1 = 0
for i in range(m):
    u, v, w = RII()
    us.append(u)
    vs.append(v)
    ws.append(w)

edges = sorted(range(1, m), key=lambda i: ws[i])
uf = UnionFind(n + 1)
ans = 10**9
for i in edges:
    u, v, w = us[i], vs[i], ws[i]
    if not uf.is_same(u, v):
        uf.union(u, v)
    if uf.is_same(us[0], vs[0]):
        ans = w
        break
print(ans)