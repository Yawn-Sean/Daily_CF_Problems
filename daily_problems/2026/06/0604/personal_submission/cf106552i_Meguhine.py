import sys

input = lambda: sys.stdin.readline().rstrip()


INF = 1 << 7
n, m, Q = map(int, input().split())
a = [bytearray([INF] * m) for _ in range(n)]

dis = [[INF] * m for _ in range(m)]
for v in a:
    b = list(map(lambda s: int(s) - 1, input().split()))[1:]
    for i, x in enumerate(b):
        v[x] = 0
        for j in range(i):
            dis[x][b[j]] = 1
for i in range(m):
    dis[i][i] = 0
for k in range(m):
    for i in range(m):
        if dis[i][k] == INF:
            continue
        for j in range(m):
            d = dis[i][k] + dis[k][j]
            if dis[i][j] > d:
                dis[i][j] = d
for v in a:
    b = [i for i, x in enumerate(v) if x == 0]
    for i in range(m):
        v[i] = min(dis[i][j] for j in b)

outs = [-1] * Q
for _case in range(Q):
    i, j = map(lambda s: int(s) - 1, input().split())
    vi, vj = a[i], a[j]
    ans = min(vi[c] + vj[c] for c in range(m))
    if ans < INF:
        outs[_case] = ans
print('\n'.join(map(str, outs)))


"""
时间复杂度: O(M^3 + N*M^2 + Q*M)
"""
