# Submission link: https://codeforces.com/gym/106394/submission/370426403
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        ans = n - 1
        
        cur = 0
        v = 0
        
        for i in range(n):
            if cur < 0:
                cur += v
                ans += 1
            
            v = fmax(v, nums[i])
            cur -= 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))