p, q = MII()
g = gcd(p, q)
p //= g
q //= g

n = II()
a = LII()
a[-1] = (a[-1], 1)

for i in range(n - 2, -1, -1):
    y, x = a[i + 1][0], a[i + 1][1]
    x += y * a[i]
    g = gcd(x, y)
    x //= g
    y //= g
    a[i] = (x, y)

a, b = a[0][0], a[0][1]
if a == p and b == q:
    print('YES')
else:
    print('NO')
