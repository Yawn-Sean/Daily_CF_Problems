# Submission link: https://codeforces.com/gym/106054/submission/346111564
def main(): 
    n, k = MII()
    nums = LII()
    mod = 998244353
    
    tmp = [0] * n
    
    for i in range(k, n):
        tmp[i] = tmp[i - k] + nums[i - k + 1] - nums[i - k]
    
    to_add = 0
    for i in range(k):
        val = 0
        for j in range(i, n, k):
            val = fmin(val, tmp[j])
        to_add -= val
    
    if to_add > nums[0]:
        print(0)
    else:
        tot = nums[0] - to_add
        v1 = 1
        v2 = 1
        
        for i in range(1, k):
            v1 = v1 * (tot + k - i) % mod
            v2 = v2 * i % mod
        
        print(v1 * pow(v2, -1, mod) % mod)