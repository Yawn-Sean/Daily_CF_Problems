def main():
    d = [119, 18, 93, 91, 58, 107, 111, 82, 127, 123]
    n, k = MII()
    res = []
    for _ in range(n):
        tmp = int(I(), 2)
        res.append(tmp)
    g = [[] for _ in range(1 << 7)]
    for i in range(1 << 7):
        for num, j in enumerate(d):
            if i & j == i:
                g[i].append([num, j.bit_count() - i.bit_count()])
        g[i].sort(reverse=True)
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[n][0] = 1
    for i in range(n - 1, -1, -1):
        x = res[i]
        if not g[res[i]]:
            return -1
        for j in range(k + 1):
            for ne, step in g[x]:
                if j >= step and dp[i + 1][j - step]:
                    dp[i][j] = 1
                    break
    ans = []
    if not dp[0][k]:
        return -1
    tot = k
    for i in range(n):
        x = res[i]
        for ne, step in g[x]:
            if tot >= step and dp[i + 1][tot - step]:
                ans.append(ne)
                tot -= step
                break
    return ''.join(map(str, ans))


T = 1
for ii in range(T):
    print(main())
