# Submission link: https://codeforces.com/gym/106500/submission/372609908
def main():
    n = II()
    nums = LGMI()
    
    cnt = [0] * 10
    pairs = [[0] * 10 for _ in range(10)]
    
    for x in nums:
        for i in range(10):
            pairs[i][x] += cnt[i]
        cnt[x] += 1
    
    inf = 10 ** 14
    
    dp = [inf] * (1 << 10)
    dp[0] = 0
    
    for i in range(1 << 10):
        for j in range(10):
            if i >> j & 1: continue
            
            ni = i | (1 << j)
            new_rev = 0
            
            for k in range(10):
                if i >> k & 1:
                    new_rev += pairs[k][j]
            
            dp[ni] = fmin(dp[ni], dp[i] + new_rev)
    
    print(dp[-1])