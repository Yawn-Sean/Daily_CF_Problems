# Submission link: https://codeforces.com/gym/106592/submission/379672116
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        k, n = MII()
        nums = LII()
        
        l, r = 0, 10 ** 9
        while l <= r:
            mid = (l + r) // 2
            
            val = 0
            for x in nums:
                val += fmin(x, mid)
            
            if val > k: r = mid - 1
            else: l = mid + 1
    
        ans = [fmin(v, r) for v in nums]
        k -= sum(ans)
        
        for i in range(n):
            if ans[i] < nums[i] and k:
                k -= 1
                ans[i] += 1
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))