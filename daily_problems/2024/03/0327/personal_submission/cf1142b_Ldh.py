# @TIME
def solve(testcase):
    n, m, q = MI()
    A = LII()
    v2i = [-1 for _ in range(n + 1)]
    for i, v in enumerate(A):
        v2i[v] = i
        
    B = LII()
    
    res = [m for _ in range(m)]
    
    nxt = [m for _ in range(n + 1)]
    G = [[m for _ in range(20)] for _ in range(m + 1)]
    
    for i in range(m - 1, -1, -1):
        idx = v2i[B[i]]
        new = A[(idx + 1) % n]
        G[i][0] = nxt[new]
        nxt[B[i]] = i
    
    # print(G)
    
    for j in range(1, 20):
        for i in range(m):
            G[i][j] = G[G[i][j - 1]][j - 1]
    
    # print(G)
    
    for i in range(m):
        tmp = n - 1
        cur = i
        for j in range(20):
            if tmp >> j & 1:
                try:
                    cur = G[cur][j]
                except:
                    assert cur == m
                    break
        # print('cur', cur)
        res[i] = cur
    
    for i in range(m - 2, -1, -1):
        res[i] = min(res[i], res[i + 1])
    # print('res', res)
    
    
    ans = []
    
    for _ in range(q):
        l, r = MI()
        l -= 1
        r -= 1
        if r >= res[l]:
            ans.append('1')
        else:
            ans.append('0')
    
    print(''.join(ans))  

for testcase in range(1):
    solve(testcase)
