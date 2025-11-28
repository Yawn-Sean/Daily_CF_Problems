# Submission link: https://codeforces.com/gym/106017/submission/350932154
def main(): 
    q = II()
    mod = 998244353
    
    def op(x, y): return 0
    
    def mapping(x, y):
        xa, xb = divmod(x, mod)
        return (xa * y + xb) % mod
    
    def composition(x, y):
        xa, xb = divmod(x, mod)
        ya, yb = divmod(y, mod)
        
        a = xa * ya % mod
        b = (xa * yb + xb) % mod
        
        return a * mod + b
    
    seg = LazySegTree(op, 0, mapping, composition, mod, q)
    pt = 0
    
    idxs = [-1] * q
    outs = []
    
    for qidx in range(q):
        query = LII()
        
        if query[0] == 1:
            x = query[1]
            seg.apply(pt, pt + 1, mod + x)
            idxs[qidx] = pt
            pt += 1
        
        elif query[0] == 2:
            x = query[1] % mod
            seg.apply(0, pt, mod + x)
        
        elif query[0] == 3:
            p = query[1]
            q = query[2]
            
            x = p * pow(q, -1, mod) % mod
            seg.apply(0, pt, x * mod)
        
        else:
            idx = query[1] - 1
            outs.append(seg.get(idxs[idx]))
    
    print('\n'.join(map(str, outs)))