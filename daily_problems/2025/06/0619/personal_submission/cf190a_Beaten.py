    fx, fy = MII()
    s = I()
    dx = dy = 0
    dc = [[0, 0]]
    n = len(s)

    for c in s:
        if (c == 'L'):
            dx -= 1
        elif (c == 'R'):
            dx += 1
        elif (c == 'U'):
            dy += 1
        elif (c == 'D'):
            dy -= 1
        dc.append([dx, dy])
    dxmax, dymax = dc[-1][0], dc[-1][1]
    for i in range(n):
        k = 0
        if dxmax:
            k = (fx - dc[i][0]) // dxmax
        elif dymax:
            k = (fy - dc[i][1]) // dymax
        if (k >= 0 and k * dxmax == fx - dc[i][0] and k * dymax == fy - dc[i][1]):
            print("Yes")
            exit()

    print("No")
