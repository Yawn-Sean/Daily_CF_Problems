t = II()
outs = []

for _ in range(t):
    n = II()
    p = [None] * n
    for i in range(n):
        a, b = MII()
        if a > b:
            a, b = b, a
        p[i] = [a, b, i]
    p.sort()
    ans = [-1] * n

    pre = inf
    idx = -2
    i = 0
    while i < n:
        cur = p[i][0]
        npre, nidx = pre, idx
        while i < n and p[i][0] == cur:
            if p[i][1] > pre:
                ans[p[i][2]] = idx + 1
            elif p[i][1] < npre:
                npre = p[i][1]
                nidx = p[i][2]
            i += 1
        pre, idx = npre, nidx
        
    outs.append(' '.join(map(str, ans)))

print('\n'.join(outs))
