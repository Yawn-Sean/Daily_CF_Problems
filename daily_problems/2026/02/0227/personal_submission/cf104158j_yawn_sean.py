# Submission link: https://codeforces.com/gym/104158/submission/364440384
def main(): 
    n, q, k = MII()
    
    nums = LII()
    nums.sort()
    
    seg = SegTree(fmax, 0, k + 5)
    outs = []
    
    for _ in range(q):
        l, r, x = MII()
        l -= 1
        if l: seg.set(l, seg.get(l) + x)
        seg.set(r, seg.get(r) - x)
        outs.append(n - bisect.bisect_left(nums, seg.all_prod()))
    
    print('\n'.join(map(str, outs)))