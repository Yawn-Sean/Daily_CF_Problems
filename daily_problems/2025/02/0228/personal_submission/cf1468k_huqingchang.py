def main():
    s = I()
    dir = {'L': [-1, 0], 'R': [1, 0], 'U': [0, 1], 'D': [0, -1]}
    routes = []
    x, y = 0, 0
    for ch in s:
        dx, dy = dir[ch]
        x += dx
        y += dy
        routes.append((x, y))
    routes = set(routes)

    def check(ox, oy):
        x1, y1 = 0, 0
        for ch in s:
            nx, ny = x1 + dir[ch][0], y1 +dir[ch][1]
            if (nx, ny) != (ox, oy):
                x1, y1 = nx, ny
        return (x1, y1) == (0, 0)

    for x, y in routes:
        if check(x, y):
            print(x, y)
            return
    print(0, 0)


T = II()
for ii in range(T):
    # print(main())
    # print(ii)
    main()
