# Submission Link: https://codeforces.com/contest/1060/submission/269643414
def main():
    n = II()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    parent = [-1] * n
    color = [0] * n

    stack = [0]
    order = []

    while stack:
        u = stack.pop()
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                color[v] = color[u] ^ 1
                stack.append(v)
        order.append(u)

    size = [1] * n
    for u in reversed(order):
        if u != 0:
            size[parent[u]] += size[u]

    cnt = sum(color)
    print((sum(x * (n - x) for x in size) + cnt * (n - cnt)) // 2)