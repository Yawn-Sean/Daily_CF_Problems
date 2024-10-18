def CF1279D():
    n = II()
    a = [LII() for _ in range(n)]
    cnt = Counter()
    for row in a:
        for x in row[1:]:
            cnt[x] += 1
    ans = 0
    d = {}
    cur = pow(n, MOD9 - 2, MOD9)
    cur2 = cur * cur % MOD9
    for row in a:
        for x in row[1:]:
            if row[0] not in d:
                d[row[0]] = pow(row[0], MOD9 - 2, MOD9)
            ans += cnt[x] * d[row[0]]
            ans %= MOD9
    print(ans * cur2 % MOD9)
