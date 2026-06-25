# Submission link: https://codeforces.com/gym/106020/submission/380104879
def main():
    n = II()
    nums = LII()
    
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    tmp = []
    for i in range(n):
        if len(path[i]) == 1:
            tmp.append(i)
    
    for i in range(n):
        if len(path[i]) > 1:
            tmp.append(i)
    
    vals = [0] * n
    pos = [0] * n
    
    for i in range(n):
        vals[i] = nums[tmp[i]]
        pos[tmp[i]] = i
    
    seg = SegTree(math.gcd, 0, vals)
    
    q = II()
    outs = []
    
    for _ in range(q):
        i, x = MII()
        i -= 1
        
        vals[pos[i]] = x
        seg.set(pos[i], x)
        
        k = fmin(16, n)
        val = seg.prod(k, n)
        
        pref = [0]
        for i in range(k - 1):
            pref.append(math.gcd(pref[-1], vals[i]))
        
        flg = False
        for i in range(k - 1, -1, -1):
            if len(path[tmp[i]]) == 1 and math.gcd(pref[i], val) == 1:
                flg = True
            val = math.gcd(vals[i], val)
        
        outs.append('Yes' if flg else 'No')
    
    print('\n'.join(outs))