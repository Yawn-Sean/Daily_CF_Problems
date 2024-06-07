
from collections import defaultdict
class UF:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)
    
def main():
    n,k = map(int, input().split())
    g = []
    xs = defaultdict(list)
    ys = defaultdict(list)
    uf = UF(n)
    for i in range(n):
        g.append(list(map(int, input().split())))
        xs[g[i][0]].append(i)
        ys[g[i][1]].append(i)
    for x in xs:
        xs[x].sort(key=lambda x: g[x][1])
        for i in range(len(xs[x])-1):
            if g[xs[x][i+1]][1] - g[xs[x][i]][1] <= k:
                uf.union(xs[x][i], xs[x][i+1])

    for y in ys:
        ys[y].sort(key=lambda x: g[x][0])
        for i in range(len(ys[y])-1):
            if g[ys[y][i+1]][0] - g[ys[y][i]][0] <= k:
                uf.union(ys[y][i], ys[y][i+1])
    time = defaultdict(int)
    for i in range(n):
        fa = uf.find(i)
        if fa not in time or time[fa] > g[i][2]:
            time[fa] = g[i][2]
    a = sorted(time.values())
    b = len(a)
    ans = b - 1
    for i in range(b):
        ans = min(ans, max(a[i], b-2-i))
    print(ans)
t = int(input())
for _ in range(t):
    input()
    main()