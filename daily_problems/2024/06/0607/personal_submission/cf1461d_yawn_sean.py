# Submission link: https://codeforces.com/contest/1461/submission/264527619
def main():
    def f(x, y):
        return x * n + y

    rnd = random.getrandbits(20)
    
    n, q = MII()
    
    nums = LII()
    nums.sort()
    acc = list(accumulate(nums, initial=0))
    
    queries = [II() for _ in range(q)]
    answer = {query + rnd: False for query in queries}
    
    segs = [f(0, n - 1)]
    
    while len(segs):
        nsegs = []
        
        for msk in segs:
            l, r = divmod(msk, n)
            if acc[r+1] - acc[l] + rnd in answer:
                answer[acc[r+1] - acc[l] + rnd] = True
            
            if nums[l] != nums[r]:
                nl = bisect.bisect_right(nums, (nums[l] + nums[r]) // 2)
                nsegs.append(f(l, nl - 1))
                nsegs.append(f(nl, r))
        
        segs = nsegs
    
    outs = []
    for query in queries:
        outs.append('Yes' if answer[query + rnd] else 'No')
    return outs