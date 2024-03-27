# https://codeforces.com/contest/924/submission/253424420

def main():
    
    n, u = MII()
    nums = LII()

    l, r = 0, 0
    ans = -1
    
    while l < n:
        while r < n and nums[r] - nums[l] <= u:
            r += 1
        
        if r - l >= 3:
            ans = max(ans, (nums[r-1] - nums[l+1]) / (nums[r-1] - nums[l]))
        
        l += 1

    print(ans)
