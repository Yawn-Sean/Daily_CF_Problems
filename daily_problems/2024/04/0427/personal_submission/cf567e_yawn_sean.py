# Submission link: https://codeforces.com/contest/567/submission/258304988
def main():
    n, m, s, t = MII()
    s -= 1
    t -= 1

    edges = []
    path = [[] for _ in range(n)]
    rev_path = [[] for _ in range(n)]

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        rev_path[v].append(w * n + u)
        edges.append((u, v, w))

    inf = 10 ** 12
    dist_s = [inf] * n
    dist_s[s] = 0
    hpq = [s]

    while hpq:
        d, u = divmod(heappop(hpq), n)
        if dist_s[u] != d:
            continue
        
        for msk in path[u]:
            w, v = divmod(msk, n)
            if dist_s[v] > d + w:
                dist_s[v] = d + w
                heappush(hpq, dist_s[v] * n + v)

    dist_t = [inf] * n
    dist_t[t] = 0
    hpq = [t]

    while hpq:
        d, u = divmod(heappop(hpq), n)
        if dist_t[u] != d:
            continue
        
        for msk in rev_path[u]:
            w, v = divmod(msk, n)
            if dist_t[v] > d + w:
                dist_t[v] = d + w
                heappush(hpq, dist_t[v] * n + v)

    rnd = random.getrandbits(32)

    dp_s = [0] * n
    dp_s[s] = 1

    for u in sorted(range(n), key=lambda x: dist_s[x]):
        for msk in rev_path[u]:
            w, v = divmod(msk, n)
            if dist_s[u] == dist_s[v] + w:
                dp_s[u] += dp_s[v]
                dp_s[u] %= rnd

    dp_t = [0] * n
    dp_t[t] = 1

    for u in sorted(range(n), key=lambda x: dist_t[x]):
        for msk in path[u]:
            w, v = divmod(msk, n)
            if dist_t[u] == dist_t[v] + w:
                dp_t[u] += dp_t[v]
                dp_t[u] %= rnd

    tot_dist = dist_s[t]
    tot_method = dp_s[t]

    outs = []
    for u, v, w in edges:
        if dist_s[u] + dist_t[v] + w == tot_dist:
            if dp_s[u] * dp_t[v] % rnd == tot_method: outs.append('YES')
            else: outs.append('CAN 1' if w > 1 else 'NO')
        elif dist_s[u] + dist_t[v] >= tot_dist - 1:
            outs.append('NO')
        else:
            outs.append(f'CAN {w - tot_dist + 1 + dist_s[u] + dist_t[v]}')

    print('\n'.join(outs))