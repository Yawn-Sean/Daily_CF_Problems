# Submission link: https://codeforces.com/gym/104333/submission/395089684
def main():
    n = II()
    v1 = LII()
    v2 = LII()
    
    ans = 0
    mod = 10 ** 9 + 7
    
    empty = [[i for i in range(n) if not msk >> i & 1] for msk in range(1 << n)]
    
    for bit in range(30):
        grid = [[0] * n for _ in range(n)]
        
        for x in range(n):
            for y in range(n):
                grid[x][y] = (v1[x] + v2[y]) >> bit & 1
        
        dp = [[0] * (1 << n) for _ in range(2)]
        dp[0][0] = 1
        
        for msk in range(1 << n):
            x = msk.bit_count()
            for y in empty[msk]:
                for i in range(2):
                    ni = i ^ grid[x][y]
                    nmsk = msk | (1 << y)
                    
                    dp[ni][nmsk] += dp[i][msk]
                    dp[ni][nmsk] %= mod
        
        ans += dp[1][(1 << n) - 1] * (1 << bit) % mod
        ans %= mod
    
    print(ans)