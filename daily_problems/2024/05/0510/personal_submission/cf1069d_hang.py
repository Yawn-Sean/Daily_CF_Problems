class UF:
    def __init__(self, n):
        self.n = n
        self.parent = list(range(n + 1))
        self.rank = [1] * (n + 1)
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return
        self.parent[yr] = xr
        self.rank[xr] += self.rank[yr]
        self.rank[yr] = 0
def main():
    n, d = map(int, input().split())
    uf = UF(n)
    cnt = [0] * (n + 1)
    cnt[1] = n
    res = []
    k = 1
    for _ in range(d):
        x, y = map(int, input().split())
        if uf.find(x) != uf.find(y):
            cnt[uf.rank[uf.find(x)]] -= 1
            cnt[uf.rank[uf.find(y)]] -= 1
            uf.union(x, y)
            cnt[uf.rank[uf.find(x)]] += 1
        else:
            k += 1
        ans = 0
        c = k
        for i in range(n, 0, -1):
            if c == 0:
                break
            t = min(c, cnt[i])
            ans += t * i
            c -= t
        res.append(ans - 1)
    print(*res,sep='\n')
main()
        