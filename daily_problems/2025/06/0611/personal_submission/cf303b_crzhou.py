n, m, x, y, a, b = MII()
g = gcd(a, b)
a //= g
b //= g
mi = min(n // a, m // b)
a *= mi
b *= mi

if x <= (a + 1) // 2:
    x1 = 0
elif n - x <= a // 2:
    x1 = n - a
else:
    x1 = x - (a + 1) // 2

if y <= (b + 1) // 2:
    y1 = 0
elif m - y <= b // 2:
    y1 = m - b
else:
    y1 = y - (b + 1) // 2

print(x1, y1, x1 + a, y1 + b)
