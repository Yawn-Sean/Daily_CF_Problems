def main():
    n, t = MII()
    s = I()
    res = []
    dot = -1
    for i in range(n):
        if s[i] == '.':
            dot = i
            res.append('.')
        else:
            res.append(int(s[i]))
    r, extra = -1, 0
    for i in range(dot + 1, n):
        if res[i] >= 5:
            r = i
            t -= 1
            extra += 1
            break
    if r == -1:
        return s
    for i in range(r, n):
        res[i] = 0
    for i in range(r - 1, dot, -1):
        res[i] += extra
        if res[i] >= 10:
            res[i] = 0
            extra = 1
        else:
            if res[i] >= 5 and t:
                extra = 1
                t -= 1
                res[i] = 0
            else:
                extra = 0
    if extra:
        for i in range(dot - 1, -1, -1):
            res[i] += extra
            if res[i] >= 10:
                res[i] = 0
                extra = 1
            else:
                extra = 0
    if extra:
        res = [1] + res
    while res and res[-1] == 0:
        res.pop()
    if res[-1] == '.':
        res.pop()
    return ''.join(map(str, res))


T = 1
for ii in range(T):
    print(main())
