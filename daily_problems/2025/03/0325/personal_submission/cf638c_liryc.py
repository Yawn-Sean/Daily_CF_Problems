'''
https://codeforces.com/problemset/submission/638/312286808
'''
# Greedy+DFS(coloring)
def solve(n: int, edges: list[list[int]]) -> list[list[int]]:
    g = [[] for _ in range(n + 1)]
    for i, (u, v) in enumerate(edges):
        g[u].append((v, i + 1))
        g[v].append((u, i + 1))
    stk = [(1, -1, -1)]
    ans = []
    while stk:
        u, p, pc = stk.pop()
        c = 1 if pc == 0 else 0
        for v, ei in g[u]:
            if v != p:
                if len(ans) == c:
                    ans.append([])
                ans[c].append(ei)
                stk.append((v, u, c))
                c = c + 2 if c + 1 == pc else c + 1
    return ans
