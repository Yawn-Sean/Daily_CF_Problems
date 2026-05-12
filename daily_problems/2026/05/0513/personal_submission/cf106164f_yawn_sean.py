# Submission link: https://codeforces.com/gym/106164/submission/374258962
def main(): 
    bound = 10 ** 18 + 5
    def add(x, y):
        return fmin(x + y, bound)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, p = MII()
        
        hs = []
        ps = []
        
        for _ in range(n):
            h_val, p_val = MII()
            hs.append(h_val)
            ps.append(p_val)
        
        order = sorted(range(n), key=lambda x: -hs[x])
        
        seg = SegTree(add, 0, n)
        seg_happiness = SegTree(add, 0, n)
        
        ans = -1
        chosen_threshold = -1
        
        for i in range(n):
            seg.set(order[i], ps[order[i]])
            seg_happiness.set(order[i], hs[order[i]])
            
            if i == n - 1 or hs[order[i]] != hs[order[i + 1]]:
                cur_pos = 0
                cur_p = p
                
                res = 0
                
                while True:
                    l, r = cur_pos, n - 1
                    while l <= r:
                        mid = (l + r) // 2
                        if ps[mid] > cur_p: l = mid + 1
                        else: r = mid - 1
                    
                    cur_pos = l
                    if cur_pos == n: break
                    
                    n_cur_pos = seg.max_right(cur_pos, lambda x: x <= cur_p)
                    cur_p -= seg.prod(cur_pos, n_cur_pos)
                    res += seg_happiness.prod(cur_pos, n_cur_pos)
                    
                    cur_pos = n_cur_pos
                
                if res >= ans:
                    ans = res
                    chosen_threshold = hs[order[i + 1]] if i != n - 1 else 0
        
        outs.append(f'{ans} {chosen_threshold}')
    
    print('\n'.join(outs))