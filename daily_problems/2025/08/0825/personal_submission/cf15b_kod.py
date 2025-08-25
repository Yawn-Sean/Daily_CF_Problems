t = ix()
for _ in range(t):
    n,m,x1,y1,x2,y2 = il()
    if x1 > x2:
        x1,x2 = x2,x1
    if y1 > y2:
        y1,y2 = y2,y1
    a = n + x1 - x2
    b = m + y1 - y2
    ans = m * n - a * b *2 + max(0, 2 * a - n) * max(0, 2 * b - m)
    print(ans)
