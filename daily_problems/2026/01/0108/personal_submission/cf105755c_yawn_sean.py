# Submission link: https://codeforces.com/gym/105755/submission/356696877
def main(): 
    n = II()
    nums = LII()
    
    vis = [0] * (1 << 22)
    
    for x in nums:
        bit = x.bit_length()
        v = (1 << bit) - 1
        vis[v ^ x] |= 1 << bit - 1
    
    for i in range(22):
        for j in range(1 << 22):
            if j >> i & 1:
                vis[j ^ (1 << i)] |= vis[j]
    
    dp = [0] * (1 << 22)
    
    for i in range(1 << 22):
        for j in range(22):
            if vis[i] >> j & 1:
                ni = i | (1 << j)
                dp[ni] = fmax(dp[ni], dp[i] + 1)
    
    print(max(dp))