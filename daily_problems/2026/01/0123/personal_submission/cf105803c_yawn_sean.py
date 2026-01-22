# Submission link: https://codeforces.com/gym/105803/submission/359172280
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        if k != n - 1:
            outs.append((-sum(nums)) % n)
        else:
            cnt = [0] * n
            for x in nums:
                cnt[(-x) % n] += 1
            
            cur = sum(i * cnt[i] for i in range(n))
            ans = cur
            
            for i in range(n):
                cur += n * cnt[i]
                cur -= n
                ans = fmin(ans, cur)
            
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))