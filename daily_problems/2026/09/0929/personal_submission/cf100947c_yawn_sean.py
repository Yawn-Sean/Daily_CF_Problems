# Submission link: https://codeforces.com/gym/100947/submission/392425820
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
    
        ans = -inf
        
        v0, v1 = sum(nums[::2]), sum(nums[1::2])
        
        for i in range(n):
            v0, v1 = v1, v0 - nums[i]
            if n % 2: v0 += nums[i]
            else: v1 += nums[i]
            
            ans = fmax(ans, v0)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))