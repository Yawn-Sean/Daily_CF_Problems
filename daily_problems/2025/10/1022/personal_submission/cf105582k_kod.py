n = ix()
p = [(0,0)]
x = y = 0
if n % 2 == 0:
    for i in range(n // 2 - 1):
        y += 25
        p += (x,y),
        x += 25
        p += (x,y),
    p += (x, 0),
else:
    for i in range(n // 2 - 1):
        y += 25
        p += (x,y),
        x += 25
        p += (x,y),
    x = max(25, x)
    p += (x, 0),
    p += (x // 25 * 9, -x // 25 * 12),

a, b = 3, 4
for x, y in p:
    print(x * a + y * b, - x * b + y * a)
