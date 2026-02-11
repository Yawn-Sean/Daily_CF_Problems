# Submission link: https://codeforces.com/gym/106225/submission/362405254
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        for i in range(n - 1):
            if nums[i] >= nums[i + 1]:
                outs.append(nums[i] // (nums[i + 1] - 1))
                break
        else:
            outs.append(fmax(nums[-1] - nums[-2], nums[-1] // (nums[-1] - nums[-2])))
    
    print('\n'.join(map(str, outs)))