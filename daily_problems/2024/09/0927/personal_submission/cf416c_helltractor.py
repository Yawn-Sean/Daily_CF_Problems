def CF416F():
    n = II()
    cs = []; ps = []
    for _ in range(n):
        c, p = MII()
        cs.append(c)
        ps.append(p)
    k = II()
    r = LII()
    r_index = sorted(range(k), key=lambda x: r[x])
    cp_index = sorted(range(n), key=lambda x: cs[x])
    
    cnt = cost = j = 0
    outs = []
    h = []
    for i in r_index:
        while j < n and cs[cp_index[j]] <= r[i]:
            heappush(h, (-ps[cp_index[j]], cp_index[j]))
            j += 1
        if h:
            p, idx = heappop(h)
            cnt += 1
            cost -= p
            outs.append(f"{idx + 1} {i + 1}")
    
    print(cnt, cost)
    print('\n'.join(outs))