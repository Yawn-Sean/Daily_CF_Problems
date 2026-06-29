# Submission link: https://codeforces.com/gym/106608/submission/380549840
def main():
    M = 10 ** 6 + 5
    pr = list(range(M))
    
    mu = [0] * M
    mu[1] = 1
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range((M - 1) // i * i, 0, -i):
                pr[j] = i
                mu[j] = -mu[j // i]
    
    def factors(x):
        v = [1]
        while x > 1:
            p = pr[x]
            c = 0
            
            while x % p == 0:
                x //= p
                c += 1
            
            l = len(v)
            for _ in range(c * l):
                v.append(v[-l] * p)
        
        return v
    
    t = II()
    outs = []
    
    cnt = [0] * M
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        for x in nums:
            for f in factors(x):
                cnt[f] += 1
        
        for _ in range(q):
            ty, idx, val = MII()
            idx -= 1
            
            if ty == 1:
                if nums[idx] % val: outs.append(0)
                else:
                    ans = 0
                    for f in factors(nums[idx] // val):
                        ans += mu[f] * cnt[f * val]
                    if val == nums[idx]: ans -= 1
                    outs.append(ans)
            else:
                for f in factors(nums[idx]):
                    cnt[f] -= 1
                nums[idx] = val
                for f in factors(nums[idx]):
                    cnt[f] += 1
        
        for x in nums:
            for f in factors(x):
                cnt[f] -= 1
    
    print('\n'.join(map(str, outs)))