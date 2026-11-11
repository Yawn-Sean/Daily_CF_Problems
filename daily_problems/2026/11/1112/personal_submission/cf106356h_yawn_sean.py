# Submission link: https://codeforces.com/gym/106356/submission/398102625
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        path = [[0] * 61 for _ in range(61)]
        
        vis = [0] * 61
        dp = [1] * 61
        
        for x in nums:
            if x:
                k = x.bit_length() - 1
                vis[k] = 1
        
        for x in nums:
            k = x.bit_length() - 1
            for j in range(k):
                if x >> j & 1 and vis[j]:
                    path[j][k] = 1
        
        for i in range(61):
            for j in range(61):
                if path[i][j]:
                    dp[j] = fmax(dp[j], dp[i] + 1)
        
        outs.append(f'{max(dp)}')
    
    print('\n'.join(outs))