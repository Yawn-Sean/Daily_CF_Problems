# 过不去，需要cpp实现
def main():
    n,m = map(int,input().split())
    g = []
    for _ in range(n):
        g.append(input())
    vis = [[0] * m for _ in range(n)]
    dp = [[-1] * m for _ in range(n)]
    nxt = {'D': 'I', 'I': 'M', 'M': 'A', 'A': 'D'}
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    ans = 0
    cur = 0

    def dfs(x,y):
        if dp[x][y] != -1:
            return dp[x][y]
        if vis[x][y]:
            exit(print('Poor Inna!'))
        vis[x][y] = 1
        res = 0
        
        for dx,dy in dirs:
            nx,ny = x+dx,y+dy
            if 0 <= nx < n and 0 <= ny < m and g[nx][ny] == nxt[g[x][y]]:
                res = max(dfs(nx,ny), res)
        if g[x][y] == 'A':
            res += 1
        vis[x][y] = 0
        dp[x][y] = res
        return res
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'D':
                cur = dfs(i,j)
                ans = max(ans,cur)
    if ans == 0:
        print('Poor Dima!')
    else:
        print(ans)
                
main()