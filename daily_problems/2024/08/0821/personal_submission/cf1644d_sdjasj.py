def solve():
    n, m, k, q = MII()
    MOD = 998244353
    ans = 1
    queries = []
    for _ in range(q):
        queries.append(LII())
    queries.reverse()
    stx, sty = set(), set()
    if n == 1 or m == 1:
        print(k)
        return      
    for x, y in queries:
        if len(stx) == n and len(sty) == m:
            break
        if len(stx) != n and y not in sty or len(sty) != m and x not in stx:
            ans = (ans * k) % MOD
        stx.add(x)
        sty.add(y)
    print(ans)