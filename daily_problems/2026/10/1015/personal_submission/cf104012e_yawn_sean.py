# Submission link: https://codeforces.com/gym/104012/submission/394463745
def main():
    n = II()
    grid = [I() for _ in range(n)]
    
    ans = 1
    mod = 998244353
    
    for i in range(n):
        dp0, dp1 = 1, 0
        
        for j in range(n):
            if grid[i][j] == '.':
                dp0, dp1 = (dp0 + dp1) % mod, 0
            elif grid[i][j] == '#':
                if j and grid[i][j - 1] == '#': continue
                dp0, dp1 = 0, dp0
            else:
                dp0, dp1 = dp0, (dp0 + dp1) % mod
        
        ans = ans * (dp0 + dp1) % mod
    
    for j in range(n):
        dp0, dp1 = 1, 0
        
        for i in range(n):
            if grid[i][j] == '.':
                dp0, dp1 = (dp0 + dp1) % mod, 0
            elif grid[i][j] == '#':
                if i and grid[i - 1][j] == '#': continue
                dp0, dp1 = 0, dp0
            else:
                dp0, dp1 = dp0, (dp0 + dp1) % mod
        
        ans = ans * (dp0 + dp1) % mod
    
    print(ans)