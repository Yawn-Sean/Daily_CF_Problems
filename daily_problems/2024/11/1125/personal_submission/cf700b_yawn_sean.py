# Submission link: https://codeforces.com/contest/700/submission/293159325
def main():
    n, k = MII()
    universities = LGMI()

    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

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

    sz = [0] * n
    for u in universities:
        sz[u] = 1

    for u in reversed(order):
        if parent[u] >= 0:
            sz[parent[u]] += sz[u]

    print(sum(fmin(2 * k - x, x) for x in sz))