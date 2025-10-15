class UF:
    def __init__(self, n):
        self.p = list(range(n))
        self.s = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        if xr != yr:
            self.p[xr] = yr
            self.s[yr] += self.s[xr]
            self.s[xr] = 0
        
    
    def get_size(self, x):
        return self.s[self.find(x)]
def main():
    n = int(input())
    a = list(map(int, input().split()))
    uf = UF(n)
    st_range = sorted(range(n), key=lambda x: a[x])
    cur = -1
    max_tot = 0

    vis = [False] * n
    cnt = [0] * (n + 1)
    tot = 0
    for pos in st_range:
        if pos > 0 and vis[pos - 1]:
            sz = uf.get_size(pos - 1)
            cnt[sz] -= 1
            tot -= 1
            uf.union(pos - 1, pos)
        if pos + 1 < n and vis[pos + 1]:
            sz = uf.get_size(pos + 1)
            cnt[sz] -= 1
            tot -= 1
            uf.union(pos, pos + 1)
        
        vis[pos] = True
        sz = uf.get_size(pos)
        cnt[sz] += 1
        tot += 1
        if cnt[sz] == tot and tot > max_tot:
            max_tot = tot
            cur = a[pos] + 1
    print(cur)


main()