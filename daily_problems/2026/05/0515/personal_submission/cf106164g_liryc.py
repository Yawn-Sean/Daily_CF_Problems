'''
https://codeforces.com/gym/106164/submission/374561407
tree, dp, manhattan distance
'''
def solve(n: int, tg: list[list[int]], ca: list[list[int]]):
    dp = [[0] * n for _ in range(8)]
    parent = [-1] * n
    dfs = [0]
    for u in dfs:
        for ec in tg[u]:
            v, w = dec(ec)
            if v != parent[u]:
                parent[v] = u
                dfs.append(v)
    ans = -2000000001
    for u in reversed(dfs):
        x, y, z = ca[u]
        dp[0][u] = x + y + z
        dp[1][u] = x + y - z
        dp[2][u] = x - y + z
        dp[3][u] = x - y - z
        dp[4][u] = -x + y + z
        dp[5][u] = -x + y - z
        dp[6][u] = -x - y + z
        dp[7][u] = -x - y - z
        for ec in tg[u]:
            v, w = dec(ec)
            if v != parent[u]:
                for m in range(8):
                    ans = pmax(ans, dp[m][u] + dp[7 ^ m][v] + w)
                    dp[m][u] = pmax(dp[m][u], dp[m][v] + w)
    return ans
