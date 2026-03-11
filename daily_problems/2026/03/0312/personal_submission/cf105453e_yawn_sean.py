# Submission link: https://codeforces.com/gym/105453/submission/366243186
def main(): 
    n = II()
    grid = [LII() for _ in range(n)]
    
    ans = 0
    
    vis = [0] * n
    cur = [grid[i][i] for i in range(n)]
    
    for _ in range(n):
        chosen = -1
        
        for i in range(n):
            if not vis[i] and (chosen == -1 or cur[i] < cur[chosen]):
                chosen = i
        
        ans += cur[chosen]
        vis[chosen] = 1
        
        for j in range(n):
            cur[j] = fmin(cur[j], grid[chosen][j])
    
    print(ans)