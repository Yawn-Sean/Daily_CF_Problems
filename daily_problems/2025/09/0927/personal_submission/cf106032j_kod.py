t = ix()
for i in range(t):
    n, m, q = il()
    a = il()
    p = [inf] * m
    c = Counter(a)
    for x in set(a):
        if c[x] % 2:
            p[x - 1] = 0
    p = p + p
    for i in range(2 * m - 2, -1, -1):
        p[i] = min(p[i], p[i + 1] + 1)
    p = p[:m]
    c = 0
    for i in range(q):
        xq = il()
        if xq[0] == 1:
            c += 1
        else:
            x = a[xq[1] - 1]
            print((x + min(p[x-1], c) - 1) % m + 1)
