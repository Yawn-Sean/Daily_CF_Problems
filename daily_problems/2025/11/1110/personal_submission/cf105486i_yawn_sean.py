# Submission link: https://codeforces.com/gym/105486/submission/348163296
def main(): 
    t = II()
    outs = []
    
    M = 2 * 10 ** 5
    f = [0] * (M + 1)
    for i in range(1, M + 1):
        for j in range(i, M + 1, i):
            f[j] += 1
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        f[0] = n
        
        vals = [0] * n
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                vals[i] = i
        
        seg = SegTree(math.gcd, 0, vals)
        
        outs.append(f[seg.all_prod()])
        
        for _ in range(q):
            idx, val = MII()
            idx -= 1
            
            nums[idx] = val
            
            if idx:
                vals[idx] = idx if nums[idx] < nums[idx - 1] else 0
                seg.set(idx, vals[idx])
            if idx + 1 < n:
                vals[idx + 1] = idx + 1 if nums[idx + 1] < nums[idx] else 0
                seg.set(idx + 1, vals[idx + 1])
            
            outs.append(f[seg.all_prod()])
    
    print('\n'.join(map(str, outs)))