def main():
    n = II()
    res = []
    for _ in range(n + 1):
        xi, yi, zi = MII()
        res.append([xi, yi, zi])
    vp, vs = MII()
    px, py, pz = MII()
    flag = False
    if res[0] == [px, py, pz]:
        print('YES')
        print(0)
        print(px, py, pz)
        return
    acc = 0
    idx = 0
    for i in range(1, n + 1):
        acc += ((res[i][0] - res[i - 1][0]) ** 2 + (res[i][1] - res[i - 1][1]) ** 2 + (res[i][2] - res[i - 1][2]) ** 2) ** 0.5
        dis = ((res[i][0] - px) ** 2 + (res[i][1] - py) ** 2 + (res[i][2] - pz) ** 2) ** 0.5
        if dis * vs <= acc * vp:
            flag = True
            idx = i
            break
    if not flag:
        exit(print('NO'))
    print('YES')
    acc -= ((res[idx][0] - res[idx - 1][0]) ** 2 + (res[idx][1] - res[idx - 1][1]) ** 2 + (res[idx][2] - res[idx - 1][2]) ** 2) ** 0.5
    baseTime = acc / vs
    mi, mx = 0, ((res[idx][0] - res[idx - 1][0]) ** 2 + (res[idx][1] - res[idx - 1][1]) ** 2 + (res[idx][2] - res[idx - 1][2]) ** 2) ** 0.5 / vs
    t = mx
    eps = 10 ** -10
    vec3 = [res[idx][0] - res[idx - 1][0], res[idx][1] - res[idx - 1][1], res[idx][2] - res[idx - 1][2]]
    mo = (vec3[0] ** 2 + vec3[1] ** 2 + vec3[2] ** 2) ** 0.5
    vsx, vsy, vsz = vec3[0] * vs / mo, vec3[1] * vs / mo, vec3[2] * vs / mo
    while mi <= mx - eps:
        mid = (mi + mx) / 2
        sTime = baseTime + mid
        x, y, z = res[idx - 1][0] + vsx * mid, res[idx - 1][1] + vsy * mid, res[idx - 1][2] + vsz * mid
        cost = ((px - x) ** 2 + (py - y) ** 2 + (pz - z) ** 2) ** 0.5 / vp
        if cost <= sTime:
            t = mid
            mx = mid
        else:
            mi = mid
    print(t + baseTime)
    print(x, y, z)


T = 1
for ii in range(T):
    # print(main())
    main()
