'''
https://codeforces.com/problemset/submission/1931/329251153
'''
# topological sort
def solve(n: int, k: int, a: list[list[int]]) -> bool:
    for r in a:
        for i in range(n):
            r[i] -= 1
    hs = set()
    g = [[] for _ in range(n)]
    indeg = [0] * n
    for r in a:
        first = True
        for x, y in pairwise(r):
            if first:
                first = False
            else:
                if not (x, y) in hs:
                    hs.add((x, y))
                    g[x].append(y)
                    indeg[y] += 1
    stk = [x for x in range(n) if indeg[x] == 0]
    nvis = 0
    while stk:
        x = stk.pop()
        nvis += 1
        for y in g[x]:
            indeg[y] -= 1
            if indeg[y] == 0:
                stk.append(y)
    return n == nvis
