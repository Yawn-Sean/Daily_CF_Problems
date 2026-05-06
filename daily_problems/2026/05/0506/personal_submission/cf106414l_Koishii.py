mod = 10 ** 9 + 7
outs = []
for _ in range(int(input())):
    n = int(input())
    d = dict()
    for i in range(n):
        x, p, q = map(int, input().split())
        if x not in d:
            d[x] = (p, q)
        else:
            p1, q1 = d[x]
            p2, q2 = p, q
            d[x] = ((p2 * q1 + p1 * q2 - p1 * p2) % mod, q1 * q2 % mod)

    a = []
    for key in d:
        a.append([key, d[key]])

    a.sort(key = lambda x: x[0])

    ans = 0
    pre = 1
    for i in range(len(a)):
        x, p, q = a[i][0], a[i][1][0], a[i][1][1]
        if x == i:
            pre = pre * p * pow(q, -1, mod) % mod
            ans = (ans + pre) % mod
        else:
            break

    outs.append(ans)

print('\n'.join(map(str, outs)))
