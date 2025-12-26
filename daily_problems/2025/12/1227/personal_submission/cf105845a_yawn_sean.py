# Submission link: https://codeforces.com/gym/105845/submission/355142992
def main(): 
    n = II()
    nums = LII()
    mod = 10 ** 9 + 7
    
    f = Factorial(n, mod)
    
    nums.sort()
    cnt = [0] * n
    
    for x in nums:
        cnt[bisect.bisect_left(nums, x)] += 1
    
    revn = pow(n, -1, mod)
    
    last_k, last_b = 0, 0
    k, b = 0, 0
    cur = -1
    resid = n
    
    for i in range(n - 1, -1, -1):
        if cnt[i]:
            if cur == -1:
                last_k, last_b = 1, 0
            else:
                rev_resid = f.inv(resid)
                vk = n * rev_resid % mod
                rev_vk_1 = pow(vk - 1, -1, mod)
                pw_vk = pow(vk, cur - nums[i], mod)
                
                vb = (mod - k) * rev_resid % mod
                fix = (mod - vb) * rev_vk_1 % mod
                last_k = ((last_k - fix) * pw_vk + fix) % mod
                
                vb = (mod - (n + b) % mod) * rev_resid % mod
                fix = (mod - vb) * rev_vk_1 % mod
                last_b = ((last_b - fix) * pw_vk + fix) % mod
            
            k = (k + last_k * cnt[i]) % mod
            b = (b + last_b * cnt[i]) % mod
            cur = nums[i]
            
            resid -= cnt[i]
    
    print((mod - last_b) * pow(last_k, -1, mod) % mod)