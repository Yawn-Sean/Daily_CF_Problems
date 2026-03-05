# Submission link: https://codeforces.com/gym/105109/submission/365480908
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        ans = 0
        
        for i in range(n):
            cur = 0
            l = i
            while l and cur + nums[l - 1] < nums[i]:
                l -= 1
                cur += nums[l]
            
            r = i + 1
            while l <= i:
                while r < n and cur + nums[r] < nums[i]:
                    cur += nums[r]
                    r += 1
                ans += r - i
                cur -= nums[l]
                l += 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))