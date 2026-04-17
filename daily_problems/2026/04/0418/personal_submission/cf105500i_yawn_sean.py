# Submission link: https://codeforces.com/gym/105500/submission/371459418
def main():
    n = II()
    nums = LII()
    
    M = 10 ** 6 + 5
    mod = 998244353
    
    f = Factorial(n, mod)
    
    cnt = [0] * M
    for x in nums:
        cnt[x] += 1
    
    mi = min(nums)
    ma = max(nums)
    
    ans = f.fac(cnt[mi])
    neighbors = cnt[mi]
    
    for i in range(mi + 1, ma + 1):
        if cnt[i] < neighbors:
            ans = 0
            break
        
        ans = ans * f.fac(cnt[i]) % mod
        ans = ans * f.combi(cnt[i] - 1, neighbors - 1) % mod
        
        neighbors = cnt[i] - neighbors
    
    if neighbors == 0: print(ans * n % mod * f.inv(cnt[mi]) % mod)
    else: print(0)