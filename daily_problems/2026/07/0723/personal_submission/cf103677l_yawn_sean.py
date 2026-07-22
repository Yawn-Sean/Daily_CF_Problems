# Submission link: https://codeforces.com/gym/103677/submission/383827548
def main():
    n = II()
    grid = [LFI() for _ in range(n)]
    
    dp = [0] * (1 << n)
    dp[-1] = 1
    
    for i in range((1 << n) - 1, 0, -1):
        v = i.bit_count()
        total = v * (v - 1) // 2
        
        for x in range(n):
            for y in range(x):
                if i >> x & 1 and i >> y & 1:
                    ni = i ^ (1 << x)
                    dp[ni] += dp[i] * grid[y][x] / total
                    ni = i ^ (1 << y)
                    dp[ni] += dp[i] * grid[x][y] / total
    
    print(*(dp[1 << i] for i in range(n)), sep='\n')