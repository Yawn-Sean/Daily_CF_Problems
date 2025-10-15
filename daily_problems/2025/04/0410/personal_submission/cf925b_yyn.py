def yyn():
    n,x1,x2 = MII()
    a = [0] + LII()
    v = [-1] * (n + 1)
    a = sorted(zip(range(n + 1),a),key=lambda x:x[1])
    s = 0
    k = -1
    for i in range(n,0,-1):
        s += 1
        t = s
        if a[i][1] < x1 / s:
            continue
        l,r = 0,n+1
        while l + 1 < r:
            mid = (l + r) >> 1
            if a[i][1] >= x1 / mid:
                r = mid
            else:
                l = mid

        t = r
        if t <= 0 or a[i][1] < x1 / t:
            t += 1
        v[i] = t

    s = 0
    vv = [False] * (n + 1)
    for i in range(n,0,-1):
        s += 1
        if a[i][1] >= x2 / s:
            vv[i] = True

        if v[i] != -1 and i + v[i] <= n and vv[i + v[i]]:
            a1 = []
            a2 = []
            for j in range(i,v[i] + i):
                a1.append(a[j][0])
            for j in range(v[i] + i,n + 1):
                a2.append(a[j][0])
            print("Yes")
            print(len(a1),len(a2))
            print(*a1)
            print(*a2)
            return

        t = s
        if a[i][1] < x2 / t:
            continue
        l, r = 0, n + 1
        while l + 1 < r:
            mid = (l + r) >> 1
            if a[i][1] >= x2 / mid:
                r = mid
            else:
                l = mid
        t = r

        if t <= 0 or a[i][1] < x2 / t:
            t += 1

        if i + t <= n and v[i + t] != -1:
            a1 = []
            a2 = []
            for j in range(i,i + t):
                a2.append(a[j][0])
            for j in range(i + t,n + 1):
                a1.append(a[j][0])
            print("Yes")
            print(len(a1), len(a2))
            print(*a1)
            print(*a2)
            return
    print("No")
