# Submission link: https://codeforces.com/gym/104599/submission/346040321
def main(): 
    n = II()
    nums = LII()
    parent = [-1] + LGMI()
    
    ans = 0
    dp1 = [0] * n
    dp2 = [0] * n
    
    for i in range(n - 1, -1, -1):
        ans = fmax(ans, dp1[i] + dp2[i])
        ans = fmax(ans, nums[i] + dp1[i])
        
        if i > 0:
            v = fmax(nums[i], dp1[i]) + 1
            p = parent[i]
            if v > dp1[p]: dp1[p], dp2[p] = v, dp1[p]
            elif v > dp2[p]: dp2[p] = v
    
    print(ans)