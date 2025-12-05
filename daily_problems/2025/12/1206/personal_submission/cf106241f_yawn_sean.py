# Submission link: https://codeforces.com/gym/106241/submission/351951384
def main(): 
    t = II()
    outs = []
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ans = 0
        
        cnt = [0] * (n + 1)
        for x in nums:
            cnt[x] += 1
        
        factor_cnt = [0] * (n + 1)
        times_cnt = [0] * (n + 1)
        
        for i in range(1, n + 1):
            for j in range(i, n + 1, i):
                factor_cnt[i] += cnt[j]
                times_cnt[j] += cnt[i]
        
        gcd_cnt = factor_cnt[:]
        lcm_cnt = times_cnt[:]
    
        for i in range(n + 1):
            gcd_cnt[i] = gcd_cnt[i] * (gcd_cnt[i] - 1)
            lcm_cnt[i] = lcm_cnt[i] * (lcm_cnt[i] - 1)
        
        for i in range(n, 0, -1):
            for j in range(i * 2, n + 1, i):
                gcd_cnt[i] -= gcd_cnt[j]
        
        for i in range(1, n + 1):
            for j in range(i * 2, n + 1, i):
                lcm_cnt[j] -= lcm_cnt[i]
        
        for i in range(1, n + 1):
            factor_cnt[i] -= cnt[i]
            times_cnt[i] -= cnt[i]
        
        for i in range(n + 1):
            gcd_cnt[i] -= cnt[i] * factor_cnt[i] % mod * 2 % mod + cnt[i] * (cnt[i] - 1) % mod
            gcd_cnt[i] %= mod
            lcm_cnt[i] -= cnt[i] * times_cnt[i] % mod * 2 % mod + cnt[i] * (cnt[i] - 1) % mod
            lcm_cnt[i] %= mod
        
        for i in range(n + 1):
            ans += lcm_cnt[i] * gcd_cnt[i]
            ans %= mod
        
        for i in range(n + 1):
            ans += cnt[i] * gcd_cnt[i] % mod * times_cnt[i] % mod * 2 % mod
            ans %= mod
            ans += cnt[i] * lcm_cnt[i] % mod * factor_cnt[i] % mod * 2 % mod
            ans %= mod
            ans += cnt[i] * (cnt[i] - 1) % mod * gcd_cnt[i] % mod
            ans %= mod
            ans += cnt[i] * (cnt[i] - 1) % mod * lcm_cnt[i] % mod
            ans %= mod
            ans += cnt[i] * (cnt[i] - 1) % mod * factor_cnt[i] % mod * times_cnt[i] % mod * 4 % mod
            ans %= mod
            ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * (factor_cnt[i] + times_cnt[i]) % mod * 2 % mod
            ans %= mod
            ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * (cnt[i] - 3) % mod
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))