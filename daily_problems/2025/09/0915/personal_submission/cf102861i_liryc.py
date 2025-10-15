'''
https://codeforces.com/gym/102861/submission/338723818
'''
def solve(n: int, a: list[int]) -> int:
    MOD = 10 ** 9 + 7
    
    pa = [-1] + [x - 1 for x in a]
    
    g = [[] for _ in range(n)]
    for i in range(1, n):
        g[pa[i]].append(i)
    
    stk = [0]
    for i in stk:
        for j in g[i]:
            stk.append(j)
        
    dp0 = [1] * n
    dp1 = [1] * n
    
    while stk:
        i = stk.pop()
        if len(g[i]) == 0:
            continue
        
        c0, c1 = 0, 1
        
        for j in g[i]:
            c0 = (c1 * dp0[j] + c0 * dp1[j]) % MOD
            c1 = c1 * dp1[j] % MOD
        
        dp0[i] = c0
        dp1[i] = (c0 + c1) % MOD
        
    return dp1[0]

