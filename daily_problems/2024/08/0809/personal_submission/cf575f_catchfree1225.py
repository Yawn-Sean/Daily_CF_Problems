import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
inf = int(1e15)

def solveTLE():
    a = set([x])
    for pi in ps:
        a.update(pi)
    a = sorted(a)
    m = len(a)
    
    # f[i][j]: 第i輪移動到位置j的成本
    f = [inf] * m
    for j in range(m):
        f[j] = abs(a[j] - x) 
    
    for l, r in ps:
        # trans_cost = 位移成本 + 原本成本
        # min(abs(a[to] - a[fr]) + f[fr]), 0<=fr<m
        # pre[to] = min(f[fr] - a[fr]) + a[to], for to <= fr
        # suf[to] = min(f[fr] + a[fr]) - a[to], for fr <= to
        pre = [inf] * m
        pre[0] = f[0] + a[0]
        for fr in range(1, m):
            pre[fr] = min(pre[fr - 1], f[fr] - a[fr])
        
        suf = [inf] * m
        suf[-1] = f[-1] + a[-1]
        for fr in range(m - 2, -1, -1):
            suf[fr] = min(suf[fr + 1], f[fr] + a[fr])
        
        nf = [inf] * m
        for to in range(m):
            trans_cost = min(pre[to] + a[to], suf[to] - a[to])
            light_cost = min(abs(a[to] - l), abs(a[to] - r)) if not l <= a[to] <= r else 0
            nf[to] = min(nf[to], trans_cost + light_cost)
        f = nf
    print(min(f))    

def solve():
    ans = 0
    l = r = x
    for nl, nr in ps:
        if l > nr:
            ans += l - nr
            l, r = nr, l
        elif r < nl:
            ans += nl - r
            l, r = r, nl
        else:
            l = max(nl, l)
            r = min(nr, r)
    print(ans)
           
for _ in range(1):
    n, x = MII()
    ps = [tuple(MII()) for _ in range(n)]
    solve()