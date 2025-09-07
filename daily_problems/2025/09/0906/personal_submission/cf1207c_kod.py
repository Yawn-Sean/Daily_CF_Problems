t = ix()
for i in range(t):
    n, a, b = il()
    s = input()
    p = [1]
    for x, y in pairwise(s):
        if x == '1' or y == '1':
            p += 2,
        else:
            p += 1,
    p += 1,

    def f(x):
        return - 2 * a + x * b

    c = []
    cc = - inf
    cnt = 0
    for x, y in pairwise(p):
        if x == 1 and y == 2:
            cnt += 1
            if cc > 0:
                c += [cc]
            cc = 0
        elif x == 1 and y == 1:
            cc += 1
        elif x == 2 and y == 1:
            cc += 1
            cnt += 1
    res = sum(p) * b + (n + cnt) * a
    for x in c:
        v = f(x)
        if v < 0:
            res += v
    print(res)


answer2:
t = ix()
for i in range(t):
    n, a, b = il()
    s = input()
    dp0, dp1 = b, inf
    for x in s:
        if x == "1":
            dp0, dp1 = inf, dp1 + a + 2 * b
        else:
            dp0, dp1 = min(dp0 + a + b, dp1 + 2 * a + b), min(dp0 + 2 * (a + b), dp1 + a + 2 * b)
    print(dp0)
