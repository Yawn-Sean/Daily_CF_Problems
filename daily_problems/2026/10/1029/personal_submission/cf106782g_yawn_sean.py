# Submission link: https://codeforces.com/gym/106782/submission/396375177
def main():
    total = II()
    gas = II()
    
    n = II()
    ps = [0]
    ds = [0]
    
    for _ in range(n):
        p, d = MII()
        
        while 2 * p + d <= 2 * ps[-1] + ds[-1]:
            ps.pop()
            ds.pop()
        
        ps.append(p)
        ds.append(d)
    
    n = len(ps)
    ans = inf
    
    seg = SegTree(fmin, inf, n)
    seg.set(0, 0)
    
    for i in range(n):
        v = seg.prod(i, n)
        
        if v < inf:
            nv = v + ds[i]
            
            if 2 * (total - ps[i]) + ds[i] <= 2 * gas:
                ans = fmin(ans, total + nv)
            
            l, r = i, n - 1
            while l <= r:
                mid = (l + r) // 2
                
                if 2 * (ps[mid] - ps[i]) + ds[i] + ds[mid] <= 2 * gas:
                    l = mid + 1
                else:
                    r = mid - 1
            
            seg.set(r, fmin(seg.get(r), nv))
    
    print(ans if ans < inf else -1)