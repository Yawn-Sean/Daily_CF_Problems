# Submission link: https://codeforces.com/gym/106439/submission/368269889
def main(): 
    M = 2 * 10 ** 5 + 5
    mod = 10 ** 9 + 7
    
    pw2 = [1] * M
    dp = [0] * M
    
    for i in range(1, M):
        pw2[i] = pw2[i - 1] * 2 % mod
    
    dp[1] = 1
    
    for i in range(2, M):
        dp[i] = (dp[i - 1] + 2 * dp[i - 2] + pw2[i - 1]) % mod
    
    t = II()
    outs = []
    
    for _ in range(t):
        outs.append(dp[II()])
    
    print('\n'.join(map(str, outs)))