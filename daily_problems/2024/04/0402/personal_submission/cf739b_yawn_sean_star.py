# Submission link: https://codeforces.com/contest/739/submission/254651215
def main():
    n = II()
    nums = LII()

    tree = [[] for _ in range(n)]
    parent = [-1] * n

    for i in range(1, n):
        p, w = MII()
        p -= 1
        tree[p].append((i, w))
        parent[i] = p

    ans = [0] * (n + 1)
    depth = [0] * n

    stack = [0]
    nodes = []
    cur_depth = []

    order = []
    while stack:
        u = stack.pop()
        if u >= 0:
            nodes.append(u)
            cur_depth.append(depth[u])
            p = bisect.bisect_left(cur_depth, depth[u] - nums[u])
            ans[parent[u]] += 1
            ans[parent[nodes[p]]] -= 1
            stack.append(~u)
            order.append(u)
            for v, w in tree[u]:
                stack.append(v)
                depth[v] = depth[u] + w
        else:
            nodes.pop()
            cur_depth.pop()

    for u in reversed(order):
        if u:
            ans[parent[u]] += ans[u]

    print(' '.join(map(str, ans[:-1])))
