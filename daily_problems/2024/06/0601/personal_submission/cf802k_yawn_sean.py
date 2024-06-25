# Submission link: https://codeforces.com/contest/802/submission/263592153
def main():
    n, k = MII()
    us = []
    vs = []
    ws = []

    path = [[] for _ in range(n)]

    for i in range(n - 1):
        u, v, w = MII()
        us.append(u)
        vs.append(v)
        ws.append(w)
        path[u].append(i)
        path[v].append(i)

    parent = [-1] * n

    stack = [0]
    order = []
    while stack:
        u = stack.pop()
        order.append(u)
        for i in path[u]:
            v = vs[i] if us[i] == u else us[i]
            if parent[u] != v:
                parent[v] = u
                stack.append(v)

    dp0 = [0] * n
    dp1 = [0] * n

    for p in reversed(order):
        val0 = []
        val1 = []
        for i in path[p]:
            v = vs[i] if us[i] == p else us[i]
            if parent[v] == p:
                val0.append(dp0[v] + ws[i])
                val1.append(dp1[v] + ws[i])
        if val0:
            tmp = nlargest(k, val0)
            dp1[p] = sum(tmp)
            dp0[p] = dp1[p]
            if len(tmp) == k:
                dp0[p] -= tmp[-1]
            to_add = -inf
            for i in range(len(val0)):
                to_add = max(to_add, val1[i] - max(val0[i], tmp[-1]))
            dp1[p] += to_add

    print(dp1[0])
