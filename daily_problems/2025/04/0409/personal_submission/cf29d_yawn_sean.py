# Submission link: https://codeforces.com/contest/29/submission/314691757
def main():
    n = II()
    path = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    is_leaf = [1] * n

    parent = [-1] * n
    que = [0]

    for u in que:
        for v in path[u]:
            if parent[u] != v:
                is_leaf[u] = 0
                parent[v] = u
                que.append(v)

    nodes = LGMI()
    k = len(nodes)

    vis = [n] * n
    for i in range(k):
        vis[nodes[i]] = i

    for i in range(n - 1, 0, -1):
        u = que[i]
        vis[parent[u]] = fmin(vis[parent[u]], vis[u])

    ans = []
    stk = [0]

    while stk:
        u = stk.pop()
        if u >= 0:
            if u > 0:
                ans.append(parent[u])
            stk.append(~u)
            path[u].sort(key=lambda x: -vis[x])
            for v in path[u]:
                if parent[v] == u:
                    stk.append(v)
        else:
            ans.append(~u)

    pt = 0
    for u in ans:
        if pt < k and nodes[pt] == u:
            pt += 1

    if pt == k: print(' '.join(str(x + 1) for x in ans))
    else: print(-1)