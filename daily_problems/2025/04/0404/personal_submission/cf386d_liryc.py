'''
https://codeforces.com/problemset/submission/386/313989021
'''
def solve(n: int, u: int, v: int, w: int, a: list[str]) -> list[str]:
    u, v, w = u - 1, v - 1, w - 1
    if u > v: u, v = v, u
    if v > w: v, w = w, v
    if u > v: u, v = v, u
    
    if u == 0 and v == 1 and w == 2:
        return [' ']

    def ec(x, y, z):
        nonlocal n
        return x * n * n + y * n + z
    def dc(m):
        nonlocal n
        y, z = divmod(m, n)
        x, y = divmod(y, n)
        return x, y, z
    
    dq = []
    dq.append(ec(u, v, w))
    rp = [-1] * n ** 3
    rp[ec(u, v, w)] = -2

    di = [[0] * n for _ in range(n)]
    
    g = [[[] for _ in range(26)] for _ in range(n)]
    for i, s in enumerate(a):
        for j, c in enumerate(s):
            if i != j:
                k = ord(c) - 97
                di[i][j] = k
                g[i][k].append(j)

    ok = False
    for m in dq:
        u, v, w = dc(m)
        for x, y, z in [(u, v, w), (v, u, w), (w, u, v)]:
            k = di[y][z]
            for t in g[x][k]:
                if t != u and t != v and t != w:
                    d, e, f = t, y, z
                    if d > e: d, e = e, d
                    if e > f: e, f = f, e
                    if d > e: d, e = e, d
                    c = ec(d, e, f)
                    if rp[c] == -1:
                        rp[c] = m << 14 | x << 7 | t 
                        if d == 0 and e == 1 and f == 2: 
                            ok = True
                            break
                        dq.append(c)
            if ok:
                break
        if ok:
            break

    if not ok:
        return []

    ans = []
    c = ec(0, 1, 2)
    while c >= 0:
        c = rp[c]
        if c < 0:
            break
        c, x, y = c >> 14, c >> 7 & 127, c & 127
        ans.append(f"{x + 1} {y + 1}")
    return ans[::-1]
