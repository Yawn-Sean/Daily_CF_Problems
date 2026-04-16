'''
https://codeforces.com/gym/105791/submission/371320981
'''
# bitmask DP
def solve(n: int, cg: list[list[int]]) -> int:
    if n == 1:
        return 0
    m = 1 << n
    dp = [[-1] * m for _ in range(n)]
    dp[0][1] = 0
    for ms in range(1, m):
        for u in range(n):
            if 1 << u & ms and dp[u][ms] >= 0:
                for v in range(n):
                    if not 1 << v & ms:
                        dp[v][ms | 1 << v] = pmin(dp[v][ms | 1 << v], cg[u][v] + dp[u][ms])   
    return min(dp[i][m - 1] + cg[i][0] for i in range(1, n))
