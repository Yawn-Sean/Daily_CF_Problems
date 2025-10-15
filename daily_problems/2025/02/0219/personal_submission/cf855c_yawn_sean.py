# Submission link: https://codeforces.com/contest/855/submission/306806275
def main():
    mod = 10 ** 9 + 7

    n, m = MII()

    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    k, x = MII()

    parent = [-1] * n
    order = []
    stk = [0]

    while stk:
        u = stk.pop()
        order.append(u)
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                stk.append(v)

    dp0 = [[0] * n for _ in range(x + 1)]
    dp1 = [[0] * n for _ in range(x + 1)]
    dp2 = [[0] * n for _ in range(x + 1)]

    for i in range(n):
        dp0[0][i] = k - 1
        dp1[1][i] = 1
        dp2[0][i] = m - k

    order.reverse()

    for u in order:
        if u == 0: break
        p = parent[u]
        
        for nx in range(x, -1, -1):
            res = 0
            for nx0 in range(nx + 1):
                res += dp0[nx - nx0][p] * (dp0[nx0][u] + dp1[nx0][u] + dp2[nx0][u]) % mod
            dp0[nx][p] = res % mod
        
        for nx in range(x, -1, -1):
            res = 0
            for nx0 in range(nx + 1):
                res += dp1[nx - nx0][p] * dp0[nx0][u] % mod
            dp1[nx][p] = res % mod
        
        for nx in range(x, -1, -1):
            res = 0
            for nx0 in range(nx + 1):
                res += dp2[nx - nx0][p] * (dp0[nx0][u] + dp2[nx0][u]) % mod
            dp2[nx][p] = res % mod

    ans = 0
    for i in range(x + 1):
        ans += dp0[i][0] + dp1[i][0] + dp2[i][0]

    print(ans % mod)