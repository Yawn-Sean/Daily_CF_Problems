import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(GMI())


n = I()
edges = [LGMI() for _ in range(n-1)]
g = [[i] for i in range(n)]
fa = [_ for _ in range(n)]


def find(x):
    r = x
    while r != fa[r]:
        r = fa[r]

    k = x
    while k != r:
        fa[k], k = r, fa[k]
    return fa[x]


def union(x, y):
    fx = find(x)
    fy = find(y)

    if len(g[fx]) < len(g[fy]):
        g[fy].extend(g[fx])
        fa[fx] = fy
    else:
        g[fx].extend(g[fy])
        fa[fy] = fx


for u, v in edges:
    union(u, v)


for i in range(n):
    if len(g[i]) == n:
        ans = g[i]

print(' '.join(str(x+1) for x in ans))
