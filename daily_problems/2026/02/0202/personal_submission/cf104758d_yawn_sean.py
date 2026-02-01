# Submission link: https://codeforces.com/gym/104758/submission/360994049
def main(): 
    n = II()
    nums = LII()
    
    pref = nums[:]
    for i in range(1, n):
        pref[i] = fmax(pref[i - 1], pref[i])
    
    suff = nums[:]
    for i in range(n - 2, -1, -1):
        suff[i] = fmax(suff[i], suff[i + 1])
    
    ans = 0
    cur = 0
    
    for i in range(n):
        x = fmin(pref[i], suff[i]) - nums[i]
        if x == 0:
            cur = 0
        else:
            cur += x
        
        ans = fmax(ans, cur)
    
    print(ans)