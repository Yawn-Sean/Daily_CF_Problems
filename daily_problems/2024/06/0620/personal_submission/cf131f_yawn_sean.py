# Submission link: https://codeforces.com/contest/131/submission/266475146
def main():
    n, m, k = MII()
    grid = [I() for _ in range(n)]
    
    cnt = [[0] * m for _ in range(n)]
    
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if grid[i][j] == '1':
                f = True
                for di, dj in dirs:
                    if grid[i+di][j+dj] != '1':
                        f = False
                        break
                if f: cnt[i][j] = 1
    
    ans = 0
    for xl in range(n):
        tmp = [0] * m
        for xr in range(xl + 2, n):
            for i in range(m):
                if cnt[xr-1][i]:
                    tmp[i] += 1
            
            l = r = 1
            cur = 0
            while l < m - 1:
                while r < m - 1 and cur < k:
                    cur += tmp[r]
                    r += 1
                if cur < k: break
                ans += m - r
                cur -= tmp[l]
                l += 1
    
    print(ans)