# Submission link: https://codeforces.com/gym/105972/submission/369110600
def main(): 
    n, k = MII()
    mod = 10 ** 9 + 7
    
    dp = [[0] * (1 << n) for _ in range(k + 1)]
    dp[0][0] = 1
    
    for i in range(k + 1):
        for j in range(1 << n):
            cnt = j.bit_count()
            smaller = 0
            for bit in range(n):
                if j >> bit & 1: continue
                ni = i + smaller - fmax(bit - cnt, 0)
                nj = j | (1 << bit)
                if ni <= k:
                    dp[ni][nj] += dp[i][j]
                    dp[ni][nj] %= mod
                smaller += 1
    
    print(dp[k][-1])