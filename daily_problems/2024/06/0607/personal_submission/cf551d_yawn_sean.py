# Submission link: https://codeforces.com/contest/551/submission/264528389
def main():
    n, k, l, mod = MII()

    if k >= 1 << l:
        print(0)
    else:
        # 最后一项是 i 且当前或和是 j
        grid = [[0] * 4 for _ in range(4)]
        for i in range(2):
            for j in range(2):
                msk = i * 2 + j
                for ni in range(2):
                    nj = j | (ni & i)
                    nmsk = ni * 2 + nj
                    grid[msk][nmsk] += 1
        
        grid_n = matrix_pow(grid, n, mod)
        dp = [[0] * 4]
        dp[0][0] = 1
        dp = matrix_mul(dp, grid_n, mod)
        
        c0 = (dp[0][0] + dp[0][2]) % mod
        c1 = (dp[0][1] + dp[0][3]) % mod
        
        ans = 1 % mod
        for i in range(l):
            if k >> i & 1: ans = ans * c1 % mod
            else: ans = ans * c0 % mod
        
        print(ans)