t = ix()
for i in range(t):
    n = ix()
    a = il()
    m = max(a)
    if m < 2: print(0)
    elif n == 2:
        x, y = a
        ans = 0
        while x > 1 or y > 1:
            ny = x >> 1
            nx = y >> 1
            ans += nx + ny
            x %= 2
            y %= 2
            x += nx
            y += ny
        print(ans)
    elif m == 3 and sum(a) == 3:
        print(1)
    else:
        print(sum(a) - 1)
