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



n, k = map(int, input().split())

ft = Fenwick(100005)

b = list(map(int, input().split()))
w = list(map(int, input().split()))
v = list(map(int, input().split()))

for i in range(n):
    ft.add(w[i], v[i])

st_range = list(range(n))
st_range.sort(key = lambda x: (b[x], w[x], v[x]))

ans = 0
pos = n - 1
for i in range(k - 1, 0, -1):
    while pos >= 0 and b[st_range[pos]] > i:
        ft.add(w[st_range[pos]], -v[st_range[pos]])
        pos -= 1
    ans = max(ans, ft.rsum(1, k - i))
    
print(ans)
