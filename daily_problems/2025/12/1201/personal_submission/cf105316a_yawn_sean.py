# Submission link: https://codeforces.com/gym/105316/submission/351366722
def main(): 
    mod = 10 ** 9 + 7
    
    n = II()
    nums = LII()
    
    pw2 = [1] * n
    for i in range(1, n):
        pw2[i] = pw2[i - 1] * 2 % mod
    
    total = sum(nums)
    
    ans = pw2[n - 1] - 1
    
    cur = 0
    for i in range(n - 1):
        cur += nums[i]
        if cur * 2 >= total:
            ans -= pw2[n - 2 - i]
            ans %= mod
        
        if cur * 2 == total:
            ans += 1
            ans %= mod
    
    cur = 0
    for i in range(n - 1, 0, -1):
        cur += nums[i]
        if cur * 2 >= total:
            ans -= pw2[i - 1]
            ans %= mod
    
    l, r = 0, 0
    cur = 0
    
    while l < n:
        while r < n and cur * 2 < total:
            cur += nums[r]
            r += 1
        
        if l > 0 and r < n:
            ans -= pw2[l - 1] * (pw2[n - r] - 1) % mod
            ans %= mod
        
        cur -= nums[l]
        l += 1
    
    print(ans)