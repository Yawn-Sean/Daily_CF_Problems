# Submission link: https://codeforces.com/gym/106527/submission/375216490
def main():  
    n, m = MII()
    s = I()
    
    path = [[] for _ in range(n)]
    indeg = [0] * n
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        indeg[v] += 1
    
    dp = [0] * n
    stk = [i for i in range(n) if indeg[i] == 0]
    
    while stk:
        u = stk.pop()
        
        for v in path[u]:
            dp[v] = fmax(dp[v], dp[u] + 1)
            indeg[v] -= 1
            if indeg[v] == 0:
                stk.append(v)
    
    if max(indeg) or max(dp) >= 67: print('NO')
    else:
        print('YES')
        print('\n'.join(s[0] for _ in range(m)))