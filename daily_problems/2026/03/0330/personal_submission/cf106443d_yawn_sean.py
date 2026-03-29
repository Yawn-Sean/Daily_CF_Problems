# Submission link: https://codeforces.com/gym/106443/submission/368675661
def main(): 
    M = 5 * 10 ** 5 + 5
    dp = [0] * M
    dp_acc = [0] * (M + 1)
    
    for i in range(1, M):
        if dp_acc[i] - dp_acc[i // 2] != i - i // 2:
            dp[i] = 1
        dp_acc[i + 1] = dp_acc[i] + dp[i]
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        outs.append('mastermei' if dp[n] else 'the greatest')
    
    print('\n'.join(outs))