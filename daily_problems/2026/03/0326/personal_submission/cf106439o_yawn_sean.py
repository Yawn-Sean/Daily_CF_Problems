# Submission link: https://codeforces.com/gym/106439/submission/368134559
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        pref = nums[:]
        for i in range(1, n):
            pref[i] = math.gcd(pref[i - 1], pref[i])
        
        suff = nums[:]
        for i in range(n - 2, -1, -1):
            suff[i] = math.gcd(suff[i + 1], suff[i])
        
        ans = [0] * (n - 1)
        for i in range(n - 1):
            if pref[i] == suff[i + 1]:
                ans[i] = 1
        
        cnt = Counter()
        for x in pref: cnt[x] = 0
        
        for i in range(n - 1, 0, -1):
            for x in cnt:
                if nums[i] % x:
                    cnt[x] += 1
            if cnt[pref[i - 1]] <= 1:
                ans[i - 1] = 1
        
        cnt = Counter()
        for x in suff: cnt[x] = 0
        
        for i in range(n - 1):
            for x in cnt:
                if nums[i] % x:
                    cnt[x] += 1
            if cnt[suff[i + 1]] <= 1:
                ans[i] = 1
        
        outs.append(str(sum(ans)))
    
    print('\n'.join(outs))