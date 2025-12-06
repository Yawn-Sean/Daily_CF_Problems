'''
https://codeforces.com/gym/106241/submission/352204606
'''
# DP + 求和优化
def solve(n: int, m: int, ne: list[list[int]]) -> list[int]:
    MOD = 998244353
    m = 2
    di = { 1:1 }
    for e in ne:
        for x in e:
            if not x in di:
                di[x] = m
                m += 1
    k = n - m + 1 
    ng = [[] for _ in range(m)]
    for i, j in ne:
        u = di[i]
        v = di[j]
        ng[u].append(v)
        ng[v].append(u)
    dp0, dp1 = [0] * m, [0] * m
    s0, s1 = 0, 0
    s0 = dp0[1] = 1
    ans = []
    for _ in range(n - 1):
        s1 = dp1[0] = s0 * k - dp0[0]
        for v in range(1, m):
            dp1[v] = s0 - dp0[v]
            for u in ng[v]:
                dp1[v] -= dp0[u]
            s1 += dp1[v]
        s0 = s1 % MOD
        for i, x in enumerate(dp1):
            dp0[i] = x % MOD
        ans.append(s0)
    return ans
