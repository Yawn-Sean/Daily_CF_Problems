# Submission link: https://codeforces.com/gym/104736/submission/363971968
def main(): 
    s = I()
    n = II()
    mod = 10 ** 9 + 7
    
    n %= mod
    
    ans = 0
    cnt = [0] * 26
    
    for c in s:
        ch = ord(c) - ord('a')
        
        for i in range(ch + 1, 26):
            ans += cnt[i]
        
        cnt[ch] += 1
    
    ans = n * ans % mod
    
    for i in range(26):
        for j in range(i):
            ans += n * (n - 1) // 2 % mod * cnt[i] % mod * cnt[j] % mod
            ans %= mod
    
    print(ans)