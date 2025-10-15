'''
https://codeforces.com/gym/105819/submission/339480591
'''
# unionfind

# edges: 0-indexed
def solve(n: int, m: int, a: list[int], edges: list[list[int]]) -> list[str]:
    ans = [[False] * n for _ in range(n)]
    for i in range(n):
        ans[i][i] = True
    uni = UnionFind(n)
    for c in range(30):
        uni.reset()
        b = 1 << c
        for u, v in edges:
            if a[u] & a[v] & b:
                uni.union(u, v)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if not ans[i][j] and uni.check(i, j):
                    ans[i][j] = ans[j][i] = True
    return [''.join('1' if b else '0' for b in r) for r in ans]
