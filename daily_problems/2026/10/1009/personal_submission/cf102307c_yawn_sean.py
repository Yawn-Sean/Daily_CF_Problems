# Submission link: https://codeforces.com/gym/102307/submission/393676329
def main():
    s1 = [ord(c) for c in I()]
    s2 = [ord(c) for c in I()]
    
    n = len(s1)
    bound = n // 100
    
    dp = [0] * (n + 1)
    
    for i in range(n):
        l = fmax(0, i - bound)
        r = fmin(n - 1, i + bound)
        
        for j in range(r, l - 1, -1):
            if s1[i] == s2[j]:
                dp[j + 1] = dp[j] + 1
        
        for j in range(l, r + 1):
            dp[j + 1] = fmax(dp[j + 1], dp[j])
    
    print('Long lost brothers D:' if dp[n] >= n - bound else 'Not brothers :(')