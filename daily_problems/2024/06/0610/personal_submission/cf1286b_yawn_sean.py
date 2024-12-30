# Submission link: https://codeforces.com/contest/1286/submission/264988380
def main():
    n = II()

    tree = [[] for _ in range(n)]

    parent = [0] * n
    counts = [0] * n

    for i in range(n):
        parent[i], counts[i] = MII()
        parent[i] -= 1
        if parent[i] >= 0:
            tree[parent[i]].append(i)

    rt = parent.index(-1)

    dfs_order = []
    stack = [rt]

    while stack:
        u = stack.pop()
        for v in tree[u]:
            stack.append(v)
        dfs_order.append(u)

    ans = [0] * n
    nodes = [[] for _ in range(n)]

    for node in reversed(dfs_order):
        stack = [node]
        while stack:
            u = stack.pop()
            for v in tree[u]:
                stack.append(v)
                nodes[ans[v]].append(v)
        tmp = []
        for i in range(1, n):
            if len(nodes[i]) == 0: break
            tmp.extend(nodes[i])
            nodes[i].clear()
        if len(tmp) < counts[node]:
            print('NO')
            break
        tmp.insert(counts[node], node)
        for i, v in enumerate(tmp, 1):
            ans[v] = i
    else:
        print('YES')
        print(' '.join(map(str, ans)))