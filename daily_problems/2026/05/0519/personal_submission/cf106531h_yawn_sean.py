# Submission link: https://codeforces.com/gym/106531/submission/375019509
def main():  
    n, m = MII()
    
    path = [[] for _ in range(n)]
    indeg = [0] * n
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        indeg[v] += 1
    
    k = II()
    invalid_notes = [[] for _ in range(n)]
    
    for i in range(k):
        j, x = MII()
        invalid_notes[x - 1].append(j)
    
    dp = [1] * n
    
    vis = [0] * n
    stk = [i for i in range(n) if indeg[i] == 0]
    
    while stk:
        u = stk.pop()
        vis[u] = 1
        
        invalid_notes[u].sort()
        for x in invalid_notes[u]:
            if dp[u] == x:
                dp[u] += 1
        
        for v in path[u]:
            indeg[v] -= 1
            dp[v] = fmax(dp[v], dp[u] + 1)
            
            if indeg[v] == 0:
                stk.append(v)
    
    print(max(dp) if sum(vis) == n else -1)