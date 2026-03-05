'''
https://codeforces.com/gym/106404/submission/365480791
'''
# dijkstra
def solve(n: int, m: int, a: list[int], tg: list[list[int]]) -> bool: 
    enc = lambda w, x: w << 18 | x
    dec = lambda e: (e >> 18, e & (1 << 18) - 1)
    da = [-1] * n
    da[0] = 0
    hp = [0]
    while hp:
        s, u = dec(heappop(hp))
        if da[u] != s:
            continue
        for e in tg[u]:
            w, v = dec(e)
            t = pmin(da[v], s + w)
            if t != da[v] and t <= a[v]:
                if v == n - 1:
                    return True
                da[v] = t
                heappush(hp, enc(t, v))
    return False
