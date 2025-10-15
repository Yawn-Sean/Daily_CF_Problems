'''
https://codeforces.com/problemset/submission/164/336720624
'''
def solve(n: int, m: int, a: list[int], edges: list[list[int]]) -> list[int]:
    dg, rg = [[] for _ in range(n)], [[] for _ in range(n)]
    for x, y in edges:
        u, v = x - 1, y - 1
        dg[u].append(v)
        rg[v].append(u)

    vis_d = [1 if x == 1 else 0 for x in a]
    stk = [i for i in range(n) if a[i] == 1]
    while stk:
        u = stk.pop()
        for v in dg[u]:
            if not vis_d[v] and not (a[v] & 1):
                vis_d[v] = 1
                stk.append(v)

    vis_r = [1 if x == 2 else 0 for x in a]
    stk = [i for i in range(n) if a[i] == 2]
    while stk:
        u = stk.pop()
        for v in rg[u]:
            if not vis_r[v]:
                vis_r[v] = 1
                if a[v] == 0:
                    stk.append(v)
    return [x & y for x, y in zip(vis_d, vis_r)]
