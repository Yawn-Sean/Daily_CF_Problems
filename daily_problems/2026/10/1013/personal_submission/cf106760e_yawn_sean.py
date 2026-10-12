# Submission link: https://codeforces.com/gym/106760/submission/394246702
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        pos = [0] * (n + 1)
        for i in range(n):
            pos[nums[i]] = i
        
        dp0 = [0] * n
        
        seg = SegTree(fmax, 0, n)
        
        for i in range(1, n + 1):
            p = pos[i]
            
            dp0[p] = seg.prod(0, p) + 1
            
            v = dp0[p]
            if p + 1 < n and nums[p] > nums[p + 1]:
                v = fmax(v, dp0[p + 1] + 1)
            
            seg.set(p, v)
        
        outs.append(f'{seg.all_prod()}')
    
    print('\n'.join(outs))