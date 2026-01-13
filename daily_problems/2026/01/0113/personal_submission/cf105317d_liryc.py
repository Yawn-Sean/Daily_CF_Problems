'''
https://codeforces.com/gym/105317/submission/357643567
'''
# 关键思路：（1）分解质因数然后状态压缩编码；（2）用前缀和和LCA查询树的路径和
def solve(n: int, a: list[int], tg: list[list[int]], q: int, qa: list[list[int]]) -> list[int]:
    prime_set = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
    pi = [-1] * 71
    for i, p in enumerate(prime_set):
        pi[p] = i
    def prime_elements(x: int):
        nonlocal prime_set
        for p in prime_set:
            if p * p > x: 
                break
            c = 0
            d, v = divmod(x, p)
            while v == 0:
                c += 1
                x = d
                d, v = divmod(x, p)
            if c:
                yield p, c
        if x > 1:
            yield x, 1
    def enc(x: int):
        nonlocal pi
        m = 0
        for e, c in prime_elements(x):
            if c & 1:
                m |= 1 << pi[e] # WA: m |= pi[e]
        return m
    ps = [0] * n
    pr = [-1] * n 
    lv = [-1] * n 
    fp = [-1] * n 
    es = [] 
    stk = deque()
    stk.append(0)
    lv[0] = 0
    while stk:
        u = stk.pop()
        if u < 0:
            u = ~u
            es.append(lv[u] << 20 | u)
        else:
            s = 0 if u == 0 else ps[pr[u]]
            ps[u] = s ^ enc(a[u])
            es.append(lv[u] << 20 | u)
            fp[u] = len(es) - 1
            for v in tg[u]:
                if lv[v] < 0:
                    pr[v] = u
                    lv[v] = lv[u] + 1
                    stk.append(~u)
                    stk.append(v)
    st = SparseTable(es) 
    def lca(u, v):
        nonlocal fp, st
        s, t = fp[u], fp[v]
        if s > t:
            s, t = t, s
        return st.query(s, t) & (1 << 20) - 1
    
    def ans(u, v):
        nonlocal pr, ps
        c = lca(u, v)
        m = ps[u] ^ ps[v] ^ ps[c]
        if c:
            m ^= ps[pr[c]]
        return 1 if m else 0

    return [ans(u, v) for u, v in qa]

