class BITS:
    def __init__(self, size):
        self.c = [0] * (size + 1)

    def modify(self, x):
        while x < len(self.c):
            self.c[x] += 1
            x += x & -x

n = int(input())
b = list(map(int, input().split()))
a = [(b[i], i + 1) for i in range(n)]
a.sort(key=lambda x: (-x[0], x[1]))

m = int(input())
q = []
for i in range(m):
    x, y = map(int, input().split())
    q.append((x, y, i + 1))
q.sort()

f = BITS(n)
ans = [0] * (m + 1)

j = 0
for i in range(m):
    while j < q[i][0]:
        j += 1
        f.modify(a[j - 1][1])

    p = 0
    s = 0
    for bit in range(19, -1, -1):
        v = p | (1 << bit)
        if v < len(f.c) and s + f.c[v] < q[i][1]:
            p = v
            s += f.c[v]

    ans[q[i][2]] = b[p]

print('\n'.join(map(str, ans[1:])))
