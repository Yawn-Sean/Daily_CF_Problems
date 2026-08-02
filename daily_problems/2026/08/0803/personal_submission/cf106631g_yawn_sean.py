# Submission link: https://codeforces.com/gym/106631/submission/385227389
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        bounds = []
        xs = []
        vs = []
        
        for _ in range(q):
            l, r, x, v = MII()
            
            bounds.append(l)
            xs.append(x)
            vs.append(-v)
            
            bounds.append(r + 1)
            xs.append(x)
            vs.append(v)
        
        
        ans = [0] * n
    
        for i in range(19, -1, -1):
            higher_msk = ~((1 << (i + 1)) - 1)
            cur_bit = 1 << i
            
            for j in range(2 * q):
                if bounds[j] & cur_bit:
                    higher = bounds[j] & higher_msk & xs[j]
                    lower = xs[j] & (cur_bit - 1)
                    ans[higher + lower] += vs[j] << i - lower.bit_count()
            
            for j in range(n):
                if j & cur_bit:
                    ans[j ^ cur_bit] += ans[j]
        
        outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))