# Submission link: https://codeforces.com/gym/105673/submission/395585650
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        ans = k
        
        for i in range(n):
            cur = k
            cur_idx = i
            
            for x in range(1, n + 1):
                cur += nums[cur_idx]
                ans = fmax(cur, ans)
                cur_idx += x
    
                if cur < 0 or cur_idx >= n: break
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))