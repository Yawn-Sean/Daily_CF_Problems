# Submission link: https://codeforces.com/contest/894/submission/262496950
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    def f(v):
        x = (math.isqrt(8 * v + 1) - 1) // 2
        return v * (x + 1) - x * (x + 1) * (x + 2) // 6

    us = []
    vs = []
    ws = []
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(v)
        us.append(u)
        vs.append(v)
        ws.append(w)

    col, k = find_SCC(path, n)

    value = [0] * k
    col_path = [[] for _ in range(k)]
    degs = [0] * k

    for i in range(m):
        u = us[i]
        v = vs[i]
        w = ws[i]
        if col[u] == col[v]:
            value[col[u]] += f(w)
        else:
            col_path[col[v]].append(w * k + col[u])
            degs[col[u]] += 1

    stack = [u for u in range(k) if degs[u] == 0]
    dp = [0] * k

    while stack:
        u = stack.pop()
        dp[u] += value[u]
        for msk in col_path[u]:
            w, v = divmod(msk, k)
            if dp[u] + w > dp[v]: dp[v] = dp[u] + w
            degs[v] -= 1
            if degs[v] == 0:
                stack.append(v)

    print(dp[col[II() - 1]])