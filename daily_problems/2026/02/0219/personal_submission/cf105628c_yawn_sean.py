# Submission link: https://codeforces.com/gym/105628/submission/363523193
def main(): 
    n, l, r, k = MII()
    nums = LII()
    
    if min(nums) <= k: print(-1)
    else:
        ans = 1
        bound = 10 ** 12
        for x in nums:
            ans = math.lcm(x, ans)
            ans = fmin(ans, bound)
        
        ans = (r - k) // ans * ans + k
        print(ans if l <= ans <= r else -1)