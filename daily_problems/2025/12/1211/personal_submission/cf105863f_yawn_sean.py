# Submission link: https://codeforces.com/gym/105863/submission/352774470
def main(): 
    t = II()
    outs = []
    inf = 2 * 10 ** 9
    
    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        seg = SegTree(fmin, inf, nums)
        
        for _ in range(q):
            x = II()
            
            pt = 0
            while x:
                pt = seg.max_right(pt, lambda val: val > x)
                if pt == n: break
                x = x % nums[pt]
            
            outs.append(x)
    
    print('\n'.join(map(str, outs)))