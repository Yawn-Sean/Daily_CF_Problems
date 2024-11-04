def CF1073C():
    n = II()
    s = I()
    x, y = MII()
    dct = {c: row for c, row in zip("UDRL", D4)}
    d = abs(x) + abs(y)

    nx = [0] * (n + 1)
    ny = [0] * (n + 1)
    for i, c in enumerate(s):
        dx, dy = dct[c]
        nx[i + 1] = nx[i] + dx
        ny[i + 1] = ny[i] + dy
    
    if d > n or (n - d) % 2:
        print(-1)
    else:
        ans = n
        l = r = 0
        check = lambda: abs(nx[l] + nx[-1] - nx[r] - x) + abs(ny[l] + ny[-1] - ny[r] - y) > r - l
        while l < n:
            while r < n and check():
                r += 1
            if check(): break
            ans = fmin(ans, r - l)
            l += 1
        print(ans)
