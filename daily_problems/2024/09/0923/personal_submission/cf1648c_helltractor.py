def CF1648C():
    n, m = MII()
    a = LII()
    b = LII()
    bit = BinaryIndexedTree(2 * 10 ** 5 + 1)
    fact = Factorial(n, MOD9)
    cnt = Counter(a)
    cur = fact.factorial(n)
    for k, v in cnt.items():
        bit.update(k, v)
        cur = cur * fact.fac_inv(v) % MOD9
    
    ans = 0
    for i, x in enumerate(b):
        if i >= n:
            ans += 1
            ans %= MOD9
            break
        cur = cur * fact.inverse(n - i) % MOD9
        ans += cur * bit.query(x - 1)
        ans %= MOD9
        if cnt[x] == 0: break
        cur = cur * cnt[x] % MOD9
        cnt[x] -= 1
        bit.update(x, -1)
    print(ans)
