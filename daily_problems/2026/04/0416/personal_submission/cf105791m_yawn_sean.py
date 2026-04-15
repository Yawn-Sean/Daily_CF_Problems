# Submission link: https://codeforces.com/gym/105791/submission/371265755
def main():  
    n = II()
    grid = [LII() for _ in range(n)]
    
    if n == 1:
        print(0)
    else:
        inf = 10 ** 9
        dp = [[inf] * (1 << n) for _ in range(n)]
        dp[0][1] = 0
    
        for i in range(1 << n):
            for j in range(n):
                if dp[j][i] < inf:
                    for nj in range(n):
                        if i >> nj & 1: continue
                        ni = i | (1 << nj)
                        dp[nj][ni] = fmin(dp[nj][ni], dp[j][i] + grid[j][nj])
    
        print(min(dp[i][(1 << n) - 1] + grid[i][0] for i in range(n)))