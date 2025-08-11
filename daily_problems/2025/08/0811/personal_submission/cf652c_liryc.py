'''
https://codeforces.com/problemset/submission/652/333539449
'''
# two pointers, counter
def solve(n: int, m: int, pa: list[int], foes: list[list[int]]) -> int:
    g = [[] for _ in range(n + 1)]
    for u, v in foes:
        g[u].append(v)
        g[v].append(u)
    ans, i, cn = 0, 0, [0] * (n + 1)
    for j, p in enumerate(pa):
        while cn[p]:
            for y in g[pa[i]]:
                cn[y] -= 1
            i += 1
        for x in g[p]:
            cn[x] += 1
        ans += j - i + 1
    return ans
