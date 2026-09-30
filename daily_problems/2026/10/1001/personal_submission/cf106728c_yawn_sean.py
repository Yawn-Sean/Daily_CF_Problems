# Submission link: https://codeforces.com/gym/106728/submission/392700710
def main():
    k, l, n = MII()
    ws = LII()
    
    if k == 1:
        print(sum(ws) * (l - 1))
    else:
        segs = []
        tags = []
        
        cur = 1
        
        for i in range(l - 1):
            segs.append([SegTree(fmin, inf, [0] * k) for _ in range(cur)])
            tags.append([0] * cur)
            cur *= k
        
        for w in ws:
            idx = 0
            
            for i in range(l - 1):
                v = segs[i][idx].all_prod()
                idx = idx * k + segs[i][idx].max_right(0, lambda x: x > v)
    
            delta = 0
    
            for i in range(l - 2, -1, -1):
                idx, pos = divmod(idx, k)
                old = segs[i][idx].all_prod()
                segs[i][idx].set(pos, segs[i][idx].get(pos) + w + delta)
                delta = segs[i][idx].all_prod() - old
        
        print(segs[0][0].all_prod())