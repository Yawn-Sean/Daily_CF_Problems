n, m = MII()
a, b1, b2, c = 0, 0, 0, 0

for i in range(n):
    row = LII()
    x = 4 * i + 2
    for j, val in enumerate(row):
        y = 4 * j + 2
        a += val
        b1 += 2 * val * x
        b2 += 2 * val * y
        c += val * (x * x + y * y)

def calc(a, b):
    if a == 0: return 0
    q = b // (8 * a)
    return q if abs(q * 8 * a - b) <= abs((q + 1) * 8 * a - b) else q + 1

x, y = calc(a, b1) * 4, calc(a, b2) * 4
print(a * (x * x + y * y) - b1 * x - b2 * y + c)
print(x // 4, y // 4)
