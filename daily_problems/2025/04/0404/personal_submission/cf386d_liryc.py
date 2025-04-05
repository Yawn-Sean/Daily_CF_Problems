'''
https://codeforces.com/problemset/submission/386/313919318
386D
2025/4/4 Y2
2100
BFS
'''
# BFS
def solve(n: int, u: int, v: int, w: int, a: list[str]) -> list[str]:
    u, v, w = sorted([u - 1, v - 1, w - 1])
    if (u, v, w) == (0, 1, 2):
        return [' ']
    dq = deque()
    dq.append([u, v, w])
    rp = {}
    rp[(u, v, w)] = (-1, -1, -1, ' ')

    di = [[0] * n for _ in range(n)]
    
    g = [[[] for _ in range(26)] for _ in range(n)]
    for i, s in enumerate(a):
        for j, c in enumerate(s):
            if i != j:
                k = ord(c) - 97
                di[i][j] = k
                g[i][k].append(j)

    ok = False
    while dq:
        u, v, w = dq.popleft()
        for x, y, z in [(u, v, w), (v, u, w), (w, u, v)]:
            k = di[y][z]
            for t in g[x][k]:
                if t != u and t != v and t != w:
                    d, e, f = sorted([t, y, z])
                    if not (d, e, f) in rp:
                        rp[(d, e, f)] = (u, v, w, f'{x + 1} {t + 1}')
                        if (d, e, f) == (0, 1, 2):
                            ok = True
                            break
                        dq.append((d, e, f))
            if ok:
                break
        if ok:
            break

    if not ok:
        return []

    ans = []
    u, v, w = 0, 1, 2
    while u >= 0:
        u, v, w, s = rp[(u, v, w)]
        if u >= 0:
            ans.append(s)
    return ans[::-1]
