# Submission link: https://codeforces.com/gym/106601/submission/379898449
def main():
    n, q = MII()
    nums = LII()
    
    pr = list(range(n + 1))
    
    for i in range(2, n + 1):
        if pr[i] == i:
            for j in range(i, n + 1, i):
                pr[j] = i
    
    M = 10 ** 6 + 5
    
    cnt = [0] * M
    
    for x in nums:
        cnt[x] += 1
    
    ans = [0] * M
    
    for x in cnt:
        ans[x] += 1
    
    for i in range(1, n + 1):
        for j in range(i * 2, n + 1, i):
            ans[i] += ans[j]
    
    def factors(x):
        if x == 0: return []
        
        res = [1]
        
        while x > 1:
            p = pr[x]
            c = 0
            while x % p == 0:
                x //= p
                c += 1
            
            l = len(res)
            for _ in range(c * l):
                res.append(res[-l] * p)
        
        return res
    
    outs = []
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            idx = query[1] - 1
            val = query[2]
            
            for x in factors(cnt[nums[idx]]):
                ans[x] -= 1
            
            cnt[nums[idx]] -= 1
            
            for x in factors(cnt[nums[idx]]):
                ans[x] += 1
            
            nums[idx] = val
            
            for x in factors(cnt[nums[idx]]):
                ans[x] -= 1
            
            cnt[nums[idx]] += 1
            
            for x in factors(cnt[nums[idx]]):
                ans[x] += 1
        
        else:
            outs.append(ans[query[1]])
    
    print('\n'.join(map(str, outs)))