import bisect

class Fenwick:
    def __init__(self, _n):
        self.n = _n
        self.t = [0] * (self.n + 1)

    def add(self, i, x):
        while i <= self.n:
            self.t[i] += x
            i += i & -i
    
    def sum(self, i):
        ans = 0
        while i:
            ans += self.t[i]
            i -= i & -i
        return ans

    def rsum(self, l, r):
        return self.sum(r) - self.sum(l - 1)


n = int(input())

h = list(map(int, input().split()))
w = list(map(int, input().split()))

e = h.copy()

e.sort()
for i in range(n):
    h[i] = bisect.bisect_left(e, h[i]) + 1

dt = Fenwick(n + 1)

ans = 0
for i in range(n):
    ans += w[i] * dt.rsum(h[i], n)
    dt.add(h[i], w[i])

print(ans)


