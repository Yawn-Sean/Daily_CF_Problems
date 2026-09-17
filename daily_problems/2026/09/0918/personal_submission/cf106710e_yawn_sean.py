# Submission link: https://codeforces.com/gym/106710/submission/390986997
def main():
    n, k = MII()
    mod = 998244353
    
    ans = 0
    cur_len = 1
    cur_len1 = 1
    
    for _ in range(n):
        cur_len = cur_len * 2 % mod
        cur_len1 = cur_len1 * 2 % (mod - 1)
        
        a = 1
        b = pow(k, cur_len1, mod)
        
        for i in range(1, k):
            a = a * (k + cur_len - i) % mod
            b = b * i % mod
        
        prob = (mod + 1 - a * pow(b, -1, mod) % mod) % mod
        
        ans = (ans + prob) % mod
    
    print(ans)