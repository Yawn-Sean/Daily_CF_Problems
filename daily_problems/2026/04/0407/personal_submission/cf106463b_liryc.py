'''
https://codeforces.com/gym/106463/submission/370046346
'''
# DP, tree, counting
MOD = 1000000007
fac = Factorial(200001, MOD)
def solve(n: int, tg: list):
    global fac, MOD
    dp = [1] * n
    pa = [1] * n # pairwise count of each node
    pr = [-1] * n # parent of each node
    dfs = [0]
    for u in dfs:
        for v in tg[u]:
            if v != pr[u]:
                pr[v] = u
                dfs.append(v)
    for u in reversed(dfs):
        c = [0, 0]
        for v in tg[u]:
            if v != pr[u]:
                pa[u] ^= pa[v]
                c[pa[v]] += 1
                dp[u] = dp[u] * dp[v] % MOD
        if c[1]:
            if c[1] > 1:
                dp[u] = dp[u] * fac.combi(c[1], c[1] >> 1) % MOD
            dp[u] = dp[u] * pow(2, c[0], MOD) % MOD            
    return dp[0]

