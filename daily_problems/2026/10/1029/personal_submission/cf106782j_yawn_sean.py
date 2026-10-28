# Submission link: https://codeforces.com/gym/106782/submission/396375704
def main(): 
    n, c = MII()
    nums = LII()
    
    ans = 0
    cur = 0
    
    for i in range(n - 1, -1, -1):
        if nums[i] > cur:
            nums[i] -= cur
            
            w = (nums[i] + c - 1) // c
            ans += w * (i + 1)
            
            cur = c * w - nums[i]
        else:
            cur -= nums[i]
    
    print(ans * 2)