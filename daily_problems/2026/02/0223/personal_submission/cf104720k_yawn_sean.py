# Submission link: https://codeforces.com/gym/104720/submission/363972476
def main(): 
    n = II()
    ls = []
    rs = []
    
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)
    
    tmp = sorted(ls + rs)
    
    st_range = sorted(range(n), key=lambda x: rs[x])
    
    seg = SegTree(fmax, 0, 2 * n)
    ans = -10 ** 18
    
    for i in st_range:
        pl = bisect.bisect_left(tmp, ls[i])
        pr = bisect.bisect_left(tmp, rs[i])
        res = seg.prod(0, pl + 1) + rs[i] * rs[i] - ls[i] * ls[i]
        seg.set(pr, fmax(seg.get(pr), res))
        ans = fmax(ans, res * 2 - rs[i] * rs[i])
    
    print(ans)