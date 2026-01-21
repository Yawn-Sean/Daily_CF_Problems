# Submission link: https://codeforces.com/gym/102862/submission/359023893
def main(): 
    M = 10 ** 6
    seg = LazySegTree(fmax, -1, add, add, 0, [-i - 1 for i in range(M + 1)])
    
    q = II()
    outs = []
    
    for _ in range(q):
        t, x = MII()
        if t == 1: seg.apply(x, M + 1, 1)
        else: seg.apply(x, M + 1, -1)
        outs.append(seg.min_left(M + 1, lambda x: x < 0))
    
    print('\n'.join(map(str, outs)))