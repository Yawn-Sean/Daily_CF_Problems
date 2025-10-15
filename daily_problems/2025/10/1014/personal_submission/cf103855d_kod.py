n = ix()
a = []
for i in range(n):
    a += il(),
def fun():
    c = [0] * (10**6 + 1)
    for i in range(n):
        c[a[i][1]] += a[i][2]
    ys = sorted((i for i in range(10**6 + 1) if c[i]), key = lambda x: -c[x] ) + [i for i in range(10**6 + 1) if not c[i]]
    res = 0
    for i in range(3):
        res += c[ys[i]]
    tmp = [[] for i in range(10 ** 6 + 1)]
    for i in range(n):
        tmp[a[i][0]] += i,
    for x in range(10 ** 6 + 1):
        cur = 0
        for idx in tmp[x]:
            cur += a[idx][2]
            c[a[idx][1]] -= a[idx][2]
        v1, v2 = 0, 0
        for idx in range(len(tmp[x]) + 2):
            val = c[ys[idx]]
            if val > v1:
                v1, v2 = val, v1
            elif val > v2:
                v2 = val
        res = max(res, cur + v1 + v2)
        for idx in tmp[x]:
            c[a[idx][1]] += a[idx][2]
    return res

a1 = fun()
for i in range(n):
    a[i][0], a[i][1] = a[i][1], a[i][0]
print(max(a1, fun()))
