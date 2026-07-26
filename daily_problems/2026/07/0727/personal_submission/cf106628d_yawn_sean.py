# Submission link: https://codeforces.com/gym/106628/submission/384314076
def main():
    t = II()
    outs = []
    
    rnd = random.getrandbits(30)
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        l = 0
        r = 29
        
        while l <= r:
            mid = (l + r) // 2
            
            msk = (1 << mid) - 1
            cnt = Counter()
            
            for x in nums:
                cnt[(x & msk) ^ rnd] += 1
            
            if max(cnt.values()) >= k: l = mid + 1
            else: r = mid - 1
        
        outs.append((k - 1) << r)
        
    print('\n'.join(map(str, outs)))