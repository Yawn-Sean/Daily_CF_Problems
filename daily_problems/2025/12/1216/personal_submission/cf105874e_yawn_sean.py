# Submission link: https://codeforces.com/gym/105874/submission/353557493
def main(): 
    M = 2 * 10 ** 5
    pr = list(range(M + 1))
    
    for i in range(2, M + 1):
        if pr[i] == i:
            for j in range(i, M + 1, i):
                pr[j] = i
    
    mod = 10 ** 9 + 7
    f = Factorial(M, mod)
    
    n, q = MII()
    nums = LII()
    
    queries = [[] for _ in range(n)]
    
    for i in range(q):
        l, r = GMI()
        queries[l].append((i, r))
    
    last_pos = [n] * (M + 1)
    
    def op(x, y): return x * y % mod
    
    seg = SegTree(op, 1, n)
    ans = [0] * q
    
    for i in range(n - 1, -1, -1):
        prs = []
        x = nums[i]
        
        while x > 1:
            p = pr[x]
            prs.append(p)
            
            while x % p == 0:
                x //= p
        
        val = 1
        for p in prs:
            if last_pos[p] < n:
                seg.set(last_pos[p], seg.get(last_pos[p]) * f.inv(p) % mod)
            val *= p
            last_pos[p] = i
        
        seg.set(i, val)
        
        for idx, r in queries[i]:
            ans[idx] = seg.prod(0, r + 1)
    
    print('\n'.join(map(str, ans)))