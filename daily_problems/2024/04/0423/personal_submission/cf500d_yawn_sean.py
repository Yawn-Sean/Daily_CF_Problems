# Submission link: https://codeforces.com/contest/500/submission/257797190
def main():
    n = II()
    path = [[] for _ in range(n)]
    us = []
    vs = []
    ws = []
    for i in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(i)
        path[v].append(i)
        us.append(u)
        vs.append(v)
        ws.append(w)

    parent = [-1] * n
    order = []
    stack = [0]

    while stack:
        u = stack.pop()
        for i in path[u]:
            v = vs[i] if us[i] == u else us[i]
            if v and parent[v] == -1:
                parent[v] = i
                stack.append(v)
        order.append(u)

    size = [1] * n
    for u in reversed(order):
        if u:
            i = parent[u]
            v = vs[i] if us[i] == u else us[i]
            size[v] += size[u]

    weight = [-1] * (n - 1)
    for i in range(1, n):
        c1 = size[i]
        c2 = n - c1
        weight[parent[i]] = c1 * c2 * (c2 - 1) // 2 + c1 * (c1 - 1) // 2 * c2

    cur = sum(x * y for x, y in zip(ws, weight))
    total_choice = math.comb(n, 3)

    q = II()
    outs = []
    for _ in range(q):
        r, w = MII()
        r -= 1
        cur += (w - ws[r]) * weight[r]
        ws[r] = w
        outs.append(cur / total_choice * 2)

    print('\n'.join(map(str, outs)))