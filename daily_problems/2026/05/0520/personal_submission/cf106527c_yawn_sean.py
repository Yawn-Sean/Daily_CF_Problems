# Submission link: https://codeforces.com/gym/106527/submission/375216048
def main():  
    t = II()
    outs = []
    
    for _ in range(t):
        n, p, x = MII()
        nums = LII()
        
        x = p - x
        
        cnt = [0] * (n + 1)
        for v in nums:
            cnt[n - v] += 1
        
        nums.clear()
        
        for i in range(n + 1):
            for _ in range(cnt[i]):
                nums.append(i)
        
        cur = 0
        ans = n
        
        for i in range(p):
            cur += nums[i]
            if x - (p - i - 1) > 0:
                ans = fmin(ans, cur // (x - (p - i - 1)))
        
        outs.append(n - ans)
    
    print('\n'.join(map(str, outs)))