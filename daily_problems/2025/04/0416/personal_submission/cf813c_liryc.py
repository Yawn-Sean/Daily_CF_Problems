'''
https://codeforces.com/problemset/submission/813/315842451
'''
# tree dfs: preorder + postorder
def solve(n: int, x: int, edges: list[list[int]]) -> int:
    x -= 1
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    preorder = [0]
    lv = [-1] * n
    lv[0] = 0
    i = 0
    while i < len(preorder):
        u = preorder[i]
        i += 1
        for v in g[u]:
            if lv[v] < 0:
                lv[v] = lv[u] + 1
                preorder.append(v)
    b = [[-1, -1] for _ in range(n)]
    ans = 0
    for u in preorder[::-1]:
        t, m = 0, -1
        if u == x:
            m = 0
        for v in g[u]:
            if lv[v] == lv[u] + 1:
                pt, pm = b[v] 
                if pm >= 0:
                    m = pm + 1
                if pt + 1 > t:
                    t = pt + 1
        b[u][:] = t, m
        if m >= 0:
            if t > m and m < lv[u]:
                ans = max(ans, lv[u] + t)
            else:
                ans = max(ans, lv[u] + m)
    return ans * 2
