for i in range(ix()):
    sx, sy, tx, ty, k = il()
    dx = abs(tx - sx)
    dy = abs(ty - sy)
    a, b = sorted([dx, dy])
    if b <= (a + 1) * k:
        print(a + b)
    else:
        print(a + b + (b - (a + 1) * k + 2 * k  - 1) // (2 * k) * 2)
