# Submission link: https://codeforces.com/gym/104922/submission/399990088
def main(): 
    n = II()
    
    N = 1 << n
    
    seg = [0] * N * 2
    lazy = [-1] * N
    
    for i, v in enumerate(MII()):
        seg[i + N] = v
    
    for i in range(N - 1, 0, -1):
        seg[i] = seg[i * 2] + seg[i * 2 + 1]
    
    q = II()
    outs = []
    
    def pushdown(pos):
        if lazy[pos] == -1: return
        
        w = lazy[pos] * (1 << n - pos.bit_length())
        seg[2 * pos] = w
        seg[2 * pos + 1] = w
        
        if pos * 2 < N:
            lazy[2 * pos] = lazy[pos]
            lazy[2 * pos + 1] = lazy[pos]
        
        lazy[pos] = -1
    
    def apply(pos, v):
        seg[pos] = v << n - pos.bit_length() + 1
        if pos < N: lazy[pos] = v
    
    def pushup(pos):
        if pos: seg[pos] = seg[2 * pos] + seg[2 * pos + 1]
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            l, r, k, v = query[1:]
            
            l += N
            r += N + 1
            l0, r0 = l, r
    
            for i in range(n, 0, -1):
                if ((l0 >> i) << i) != l0:
                    pushdown((l0 >> i) ^ (k >> i))
                if ((r0 >> i) << i) != r0:
                    pushdown(((r0 - 1) >> i) ^ (k >> i))
    
            for i in range(n + 1):
                if l == r:
                    break
                if l & 1:
                    apply(l ^ (k >> i), v)
                    l += 1
                if r & 1:
                    r -= 1
                    apply(r ^ (k >> i), v)
                l >>= 1
                r >>= 1
    
            for i in range(1, n + 1):
                if ((l0 >> i) << i) != l0:
                    pushup((l0 >> i) ^ (k >> i))
                if ((r0 >> i) << i) != r0:
                    pushup(((r0 - 1) >> i) ^ (k >> i))
                
        else:
            l, r, k = query[1:]
            
            ans = 0
            l += N
            r += N + 1
            l0, r0 = l, r
    
            for i in range(n, 0, -1):
                if ((l0 >> i) << i) != l0:
                    pushdown((l0 >> i) ^ (k >> i))
                if ((r0 >> i) << i) != r0:
                    pushdown(((r0 - 1) >> i) ^ (k >> i))
    
            for i in range(n + 1):
                if l == r:
                    break
                if l & 1:
                    ans += seg[l ^ (k >> i)]
                    l += 1
                if r & 1:
                    r -= 1
                    ans += seg[r ^ (k >> i)]
                l >>= 1
                r >>= 1
    
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))