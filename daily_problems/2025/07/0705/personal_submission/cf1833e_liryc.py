'''
https://codeforces.com/problemset/submission/1833/327466462
'''
# dsu
def solve(n: int, a: list[int]) -> list[int]:
    ans_max, ans_min = -1, n + 1
    uni = UnionFind(n)
    g = [[] for _ in range(n)]
    for i, x in enumerate(a):
        u, v = i, x - 1
        uni.union(u, v)
        if not g[u] or len(g[u]) == 1 and g[u][0] != v:
            g[u].append(v)
        if not g[v] or len(g[v]) == 1 and g[v][0] != u:
            g[v].append(u)
    c1 = sum(len(g[t]) == 1 for t in range(n)) >> 1 # number of chains
    ans_max = uni.groupCount()
    ans_min = ans_max - (c1 - 1 if c1 else 0) 
    return [ans_min, ans_max]
