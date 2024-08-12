    for _ in range(times):
        n = ix()
        d_edge = {} # dict of edges
        g = [frozenset()] * n
        vn = [1] * n  # 每个点的值,用来加到3
        for i in range(1,n):
            a,b = il()
            a-=1
            b-=1
            d_edge[frozenset({a,b})] = i
            g[a] |= {b}
            g[b] |= {a} # 这样degree就不用单写了,直接 len 一下就是degree
        if n % 3: print(-1);continue
        run = [i for i in range(n) if len(g[i]) == 1]
        ans = []
        while run:
            t = run.pop()
            if len(g[t]) == 0 and vn[t] != 3: print(-1); break
            for nxt in g[t]:
                vn[nxt] += vn[t]
                g[nxt] -= {t}   # 去掉叶子
                if vn[nxt] == 3:
                    for x in g[nxt]:
                        g[x] -= {nxt} # cut
                        if len(g[x]) == 1:
                            run += x,
                        ans += d_edge[frozenset({x, nxt})],
                elif vn[nxt] > 3:
                    print(-1)
                    break
                else:
                    if len(g[nxt]) == 1: run += nxt,
            else: continue
            break
        else:
            print(len(ans))
            pl(ans)
