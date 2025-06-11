# Submission link: https://codeforces.com/contest/979/submission/290617719
def main():
    n, x, y = MII()
    x -= 1
    y -= 1
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    parent = [-1] * n
    order = []

    stk = [x]
    while stk:
        u = stk.pop()
        order.append(u)
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                stk.append(v)

    size = [1] * n
    for u in reversed(order):
        if parent[u] >= 0:
            size[parent[u]] += size[u]

    szy = size[y]

    while parent[y] != x:
        y = parent[y]
    szx = n - size[y]

    print(n * (n - 1) - szx * szy)