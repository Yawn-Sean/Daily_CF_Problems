# Submission link: https://codeforces.com/gym/104745/submission/387889417
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, k = MII()
        
        path = [[] for _ in range(n)]
        indeg = [0] * n
        
        for _ in range(m):
            u, v = GMI()
            path[u].append(v)
            indeg[v] += 1
        
        starts = []
        ends = []
        
        for _ in range(k):
            s, e = GMI()
            starts.append(s)
            ends.append(e)
        
        target, start = MII()
        start -= 1
        
        stk = [i for i in range(n) if indeg[i] == 0]
        topo = []
        
        while stk:
            u = stk.pop()
            topo.append(u)
            
            for v in path[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    stk.append(v)
        
        from_start = [-inf] * n
        from_start[start] = 0
        
        for i in topo:
            for j in path[i]:
                from_start[j] = fmax(from_start[j], from_start[i] + 1)
        
        if max(from_start) >= target:
            outs.append(0)
            continue
        
        to_end = [0] * n
        
        for i in reversed(topo):
            for j in path[i]:
                to_end[i] = fmax(to_end[i], to_end[j] + 1)
        
        v0 = [from_start[x] + 1 for x in starts]
        v1 = [to_end[x] for x in ends]
        
        if max(v0[i] + v1[i] for i in range(k)) >= target:
            outs.append(1)
            continue
        
        tmp = [-inf] * n
        transition = [[-inf] * k for _ in range(k)]
        
        for i in range(k):
            tmp[ends[i]] = 0
            
            for u in topo:
                for v in path[u]:
                    tmp[v] = fmax(tmp[v], tmp[u] + 1)
            
            for j in range(k):
                transition[i][j] = tmp[starts[j]] + 1
            
            for u in range(n):
                tmp[u] = -inf
        
        def f(i, j): return i * k + j
    
        nth_transition = [[-inf] * (k * k) for _ in range(30)]
        
        for i in range(k):
            for j in range(k):
                nth_transition[0][f(i, j)] = transition[i][j]
        
        for i in range(29):
            for u in range(k):
                for v in range(k):
                    for w in range(k):
                        nth_transition[i + 1][f(u, w)] = fmax(nth_transition[i + 1][f(u, w)], nth_transition[i][f(u, v)] + nth_transition[i][f(v, w)])
        
        ans = 2
        
        for i in range(29, -1, -1):
            flg = True
            for u in range(k):
                for v in range(k):
                    if v0[u] + nth_transition[i][f(u, v)] + v1[v] >= target:
                        flg = False
            
            if flg:
                ans += 1 << i
                nv0 = [-inf] * k
                for u in range(k):
                    for v in range(k):
                        nv0[v] = fmax(nv0[v], v0[u] + nth_transition[i][f(u, v)])
                v0 = nv0
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))