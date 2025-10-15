'''
https://codeforces.com/problemset/submission/917/326026993
'''
# game dp / dpdfs
def solve(n: int, m: int, edges: list[tuple[int, int, str]]) -> list[list[str]]:
    ALL_LOSE = (1 << 26) - 1
    g = [[] for _ in range(n)]
    for v, u, c in edges:
        g[v - 1].append([ord(c) - 97, u - 1])
    dp = [[[0, 0] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        if not g[i]: # 起始位置无法移动，先手必输
            for j in range(n):
                dp[i][j][:] = 0, ALL_LOSE
        else:
            g[i].sort() 
            dp[i][i][:] = 0, ALL_LOSE # 双方起点同一个点，先手必输

    def dpdfs(v, u, c):
        nonlocal dp
        ci = 25 - c
        wi, lo = dp[v][u]
        if (wi >> c | lo >> ci) & 1:
            return wi >> c & 1
        i = 0
        while i < len(g[v]) and g[v][i][0] < c:
            i += 1
        ans = any(not dpdfs(u, nv, nc) for nc, nv in g[v][i:])
        if ans:
            dp[v][u][0] |= (1 << c + 1) - 1
        else:
            dp[v][u][1] |= (1 << ci + 1) - 1
        return ans

    for i in range(n):
        for j in range(n):
            dpdfs(i, j, 0)

    return [['A' if dp[i][j][0] else 'B' for j in range(n)] for i in range(n)]

