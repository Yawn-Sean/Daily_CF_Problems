def main():
    mod = 10 ** 9 + 7
    n, l = MII()
    res = []
    idx = -1
    neighbour = dict()
    for _ in range(n):
        a, b = MII()
        if a == b:
            res.append([a, b])
            idx += 1

        else:
            res.append([a, b])
            res.append([b, a])
            idx += 2
            neighbour[idx] = idx - 1
            neighbour[idx - 1] = idx

    tot = len(res)
    g = [[] for _ in range(tot)]
    for i in range(tot - 1):
        for j in range(i + 1, tot):
            if res[i][0] == res[j][1]:
                if i != neighbour.get(j):
                    g[i].append(j)
            if res[j][0] == res[i][1]:
                if i != neighbour.get(j):
                    g[j].append(i)
    dp = [[0] * tot for _ in range(l + 1)]
    for i, [a, b] in enumerate(res):
        if a <= l:
            dp[a][i] += 1
    for i in range(1, l + 1):
        for j in range(tot):
            if res[j][0] >= i:
                continue
            for ne in g[j]:
                dp[i][j] += dp[i - res[j][0]][ne]
            dp[i][j] %= mod
    return sum(dp[l]) % mod


T = 1
for ii in range(T):
    print(main())
