# Submission link: https://codeforces.com/gym/106439/submission/368384724
def main(): 
    M = 10 ** 6 + 5
    mod = 998244353
    
    mis = [0] * M
    mis[0] = 1
    for i in range(2, M):
        mis[i] = (i - 1) * (mis[i - 1] + mis[i - 2]) % mod
    
    dp = [0] * M
    for i in range(3, M):
        dp[i] = (dp[i - 1] + (i - 1) * mis[i - 1]) % mod * i % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append(dp[n])
    
    print('\n'.join(map(str, outs)))