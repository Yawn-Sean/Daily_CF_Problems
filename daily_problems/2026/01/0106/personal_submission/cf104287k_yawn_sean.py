# Submission link: https://codeforces.com/gym/104287/submission/356448797
def main(): 
    mod = 10 ** 9 + 7
    f = Factorial(1000, mod)
    
    t = II()
    outs = []
    
    rev26 = pow(26, -1, mod)
    pw_rev26 = [1] * 1001
    
    for i in range(1000):
        pw_rev26[i + 1] = pw_rev26[i] * rev26 % mod
    
    for _ in range(t):
        s = I()
        
        cnt = [0] * 26
        to_fill = 0
        
        for c in s:
            if 'a' <= c <= 'z':
                cnt[ord(c) - ord('a')] += 1
            else:
                to_fill += 1
        
        dp = [0] * (to_fill + 1)
        dp[0] = 1
        
        for i in range(26):
            for j in range(to_fill, -1, -1):
                if dp[j]:
                    for k in range(1, to_fill - j + 1):
                        dp[j + k] += dp[j] * f.fac_inv(cnt[i] + k) % mod * f.fac_inv(k) % mod
                        dp[j + k] %= mod
                    dp[j] = dp[j] * f.fac_inv(cnt[i]) % mod
        
        outs.append(dp[to_fill] * f.fac(to_fill) % mod * f.fac(len(s)) % mod * pw_rev26[to_fill] % mod)
    
    print('\n'.join(map(str, outs)))