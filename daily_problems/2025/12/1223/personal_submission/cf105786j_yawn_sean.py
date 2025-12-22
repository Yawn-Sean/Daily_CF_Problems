# Submission link: https://codeforces.com/gym/105786/submission/354504475
def main(): 
    t = II()
    outs = []
    
    inf = 10 ** 18
    def f(x, l, r, c):
        if l <= x <= r: return c
        if x < l: return l - x + c
        return x - r + c
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        ls = nums[:]
        rs = nums[:]
        cost = [0] * n
        
        while len(ls) > 1:
            nls, nrs, ncost = [], [], []
            
            for i in range(0, len(ls), 4):
                l, r, cur = 0, 0, inf
                
                for j in range(i, i + 4):
                    v = 0
                    for k in range(i, i + 4):
                        v += f(ls[j], ls[k], rs[k], cost[k])
                    
                    if v < cur:
                        cur = v
                        l = ls[j]
                        r = ls[j]
                    elif v == cur:
                        l = fmin(l, ls[j])
                        r = fmax(r, ls[j])
                    
                    v = 0
                    for k in range(i, i + 4):
                        v += f(rs[j], ls[k], rs[k], cost[k])
                    
                    if v < cur:
                        cur = v
                        l = rs[j]
                        r = rs[j]
                    elif v == cur:
                        l = fmin(l, rs[j])
                        r = fmax(r, rs[j])
                
                nls.append(l)
                nrs.append(r)
                ncost.append(cur)
            
            ls = nls
            rs = nrs
            cost = ncost
        
        outs.append(f(0, ls[0], rs[0], cost[0]))
    
    print('\n'.join(map(str, outs)))