N, M = map(int, input().split())

g = [[] for _ in range(N)]

for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)

def get(x: int, y: int) -> int:
    return x * N + y

dst = [-1] * (N * N)
ma = [[-1] * 3 for _ in range(N)]
ma_rev = [[-1] * 3 for _ in range(N)]
q = [0] * N

for i in range(N):
    dst[get(i, i)] = 0
    q[0] = i
    f, b = 0, 1
    while b - f:
        u = q[f]
        f += 1
        for v in g[u]:
            if dst[get(i, v)] == -1:
                dst[get(i, v)] = dst[get(i, u)] + 1
                q[b] = v
                b += 1

for i in range(N):
    for j in range(N):
        if dst[get(i, j)] > 0:
            if ma[i][0] == -1 or dst[get(i, j)] >= dst[get(i, ma[i][0])]:
                ma[i][0], ma[i][1], ma[i][2] = j, ma[i][0], ma[i][1]
            elif ma[i][1] == -1 or dst[get(i, j)] >= dst[get(i, ma[i][1])]:
                ma[i][1], ma[i][2] = j, ma[i][1]
            elif ma[i][2] == -1 or dst[get(i, j)] >= dst[get(i, ma[i][2])]:
                ma[i][2] = j

for i in range(N):
    for j in range(N):
        if dst[get(i, j)] > 0:
            if ma_rev[j][0] == -1 or dst[get(i, j)] >= dst[get(ma_rev[j][0], j)]:
                ma_rev[j][0], ma_rev[j][1], ma_rev[j][2] = i, ma_rev[j][0], ma_rev[j][1]
            elif ma[i][1] == -1 or dst[get(i, j)] >= dst[get(ma_rev[j][1], j)]:
                ma_rev[j][1], ma_rev[j][2] = i, ma_rev[j][1]
            elif ma[i][2] == -1 or dst[get(i, j)] >= dst[get(ma_rev[j][2], j)]:
                ma_rev[j][2] = i

res = 0
ans = []

for b in range(N):
    for c in range(N):
        if dst[get(b, c)] <= 0:
            continue
        for i in range(3):
            a = ma_rev[b][i]
            if ~a and a != b and a != c:
                for j in range(3):
                    d = ma[c][j]
                    if ~d and a != d and b != d and c != d:
                        t = dst[get(a, b)] + dst[get(b, c)] + dst[get(c, d)]
                        if t > res:
                            ans = [a, b, c, d]
                            res = t
print(' '.join(str(x + 1) for x in ans))