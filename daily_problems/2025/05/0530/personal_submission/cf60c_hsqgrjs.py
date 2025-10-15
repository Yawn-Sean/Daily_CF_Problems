import sys
import math
from collections import deque
rd = lambda : int(sys.stdin.readline())
rds = lambda : list(map(int, sys.stdin.readline().strip().split()))

out = []

e = [[] for _  in range(101)]

def solve() :
    global out, e
    n, m = rds()
    for i in range(m) :
        u, v, l, g = rds()
        e[u].append((v, g, l))
        e[v].append((u, g, l))
    
    vis = [False for _ in range(n + 1)]
    ans = [1 for _ in range(n + 1)]

    def check(u : int) -> bool :
        nonlocal vis, ans
        d = [(u, 0)] 
        S = set()
        S.add(u)
        while d :
            u, f = d[-1]
            vis[u] = True
            d.pop()
            for v, g, l in e[u] :
                if v != f :
                    if v not in S :
                        ans[v] = g // ans[u] * l
                    if ans[u] % l == 0 and g % ans[u] == 0 and math.gcd(ans[u] // l, ans[v] // l) == 1 :
                        if v not in S:
                            S.add(v)
                            d.append((v, u))
                    else :
                        return False
        return True
        pass

    
    for i in range(1, n + 1) :
        if vis[i] :
            continue
        
        if not e[i] :
            continue
        
        V, G, L = e[i][0]
        T = math.gcd(G, L)
        L //= T
        G //= T
        ok = False
        for j in range(1, G + 1) :
            if j * j > G :
                break 
            if G % j == 0 and math.gcd(j, G // j) == 1 :
                ans[i] = j * T
                if check(i) :
                    ok = True
                    break
                ans[i] = G // j * T
                if check(i) :
                    ok = True
                    break
        if ok == False :
            out.append(f'NO')
            return
    
    out.append('YES\n')
    for i in range(1, n + 1) :
        out.append(f'{ans[i]} ')
    pass

if __name__ == '__main__' :
    solve()
    sys.stdout.write(''.join(out) + '\n')
