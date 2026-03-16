# Submission link: https://codeforces.com/gym/106259/submission/366884955
def main(): 
    t = II()
    outs = []
    mod = 998244353
    
    for _ in range(t):
        n = II()
        nums = LII()
        nums.sort()
        
        ans = 0
        for i in range(1, n):
            ans = (ans + i * (n - i) * (nums[i] - nums[i - 1])) % mod
        
        outs.append(ans * 2 * pow(n, -1, mod) % mod)
    
    print('\n'.join(map(str, outs)))