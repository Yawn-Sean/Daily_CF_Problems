# Submission link: https://codeforces.com/gym/104146/submission/399483068
def main(): 
    n = II()
    nums = LII()
    
    ans = []
    
    for _ in range(n - 1):
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                ans.append('S')
            ans.append('P')
        ans.append('P')
    
    print(''.join(ans))