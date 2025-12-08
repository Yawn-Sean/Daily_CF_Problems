'''
https://codeforces.com/gym/106039/submission/352494396
'''
# shortest path + DP
def solve(n: int, m: int, s: int, t: int, g: list[list[int]]) -> int:
    MOD = 1000000007
    sd = [-1] * n 
    max_dist = -1
    sd[s] = 0
    qu = deque()
    qu.append(s)
    while qu:
        u = qu.popleft()
        if max_dist > 0 and sd[u] >= max_dist:
            break
        for v in g[u]:
            if sd[v] < 0:
                sd[v] = sd[u] + 1
                qu.append(v)
                if v == t:
                    max_dist = sd[v]
    dp0, dp1 = [0] * n, [0] * n
    dp0[s] = 1
    qu.clear()
    qu.append(s)
    t1, t2 = 1 << 20, 2 << 20
    mg = t1 - 1
    sd[s] |= t1
    while qu:
        m = qu.popleft()
        if m & t1:
            u = m ^ t1
            for v in g[u]:
                su, sv = sd[u] & mg, sd[v] & mg
                if su + 2 == sv + 1:
                    dp1[v] = (dp1[v] + dp1[u]) % MOD
                    if not sd[v] & t2:
                        sd[v] |= t2
                        qu.append(t1 | v)
        else:
            u = m
            for v in g[u]:
                su, sv = sd[u] & mg, sd[v] & mg
                if su + 1 == sv:
                    dp0[v] = (dp0[v] + dp0[u]) % MOD
                    if not sd[v] & t1:
                        sd[v] |= t1
                        qu.append(v)
                elif su == sv: 
                    dp1[v] = (dp1[v] + dp0[u]) % MOD
                    if not sd[v] & t2:
                        sd[v] |= t2
                        qu.append(t1 | v)
    return dp1[t]
