# Submission link: https://codeforces.com/contest/2195/submission/363067242
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        total = (nums[0] + nums[-1]) // (n - 1)
        
        ans = [0] * n
        cur = 0
        for i in range(n - 1):
            ans[i] = -(nums[i] - nums[i + 1] - total) // 2 - cur
            cur += ans[i]
        
        ans[-1] = total - cur
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(map(str, outs)))