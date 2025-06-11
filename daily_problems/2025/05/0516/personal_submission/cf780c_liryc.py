'''
https://codeforces.com/problemset/submission/780/319849943
'''
# Tree DFS
def solve(n: int, edges: list[list[int]]) -> list[int]:
    tg = [[] for _ in range(n + 1)]
    for u, v in edges:
        tg[u].append(v)
        tg[v].append(u)
    stk = []
    max_color = 1
    colors = [0] * (n + 1)
    colors[1] = 1
    stk.append((-1, 1))
    while stk:
        p, s = stk.pop()
        pc, sc = -1, colors[s]
        if p > 0:
            pc = colors[p]
        nc = 1
        while nc == pc or nc == sc:
            nc += 1
        for t in tg[s]:
            if t != p:
                colors[t] = nc
                if nc > max_color:
                    max_color = nc
                stk.append((s, t))
                nc += 1
                while nc == pc or nc == sc:
                    nc += 1     
    colors[0] = max_color
    return colors