# Submission link: https://codeforces.com/gym/106367/submission/363300519
def main(): 
    n, q = MII()
    nums = LII()
    seg = SegTree(fmax, -1, nums)
    
    outs = []
    for _ in range(q):
        l, r, val = MII()
        l -= 1
        
        ans = 0
        
        while True:
            l = seg.max_right(l, lambda x: x < val)
            if l >= r: break
            
            ans += nums[l]
            seg.set(l, -1)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))