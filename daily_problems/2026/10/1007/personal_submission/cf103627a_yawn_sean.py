# Submission link: https://codeforces.com/gym/103627/submission/393379752
def main():
    q = II()
    
    queries = []
    tmp = []
    
    for _ in range(q):
        t, s, x, y = MII()
        queries.append((t, s, x, y))
        diff = x - y if s == 1 else y - x
        tmp.append((diff, s, x, y))
    
    tmp.sort()
    
    cnt = [0] * q
    
    def e():
        return (inf, inf, inf, inf, inf)
    
    def op(x, y):
        return (fmin(fmin(x[0], y[0]), fmin(x[2] + y[4], x[3] + y[1])), fmin(x[1], y[1]), fmin(x[2], y[2]), fmin(x[3], y[3]), fmin(x[4], y[4]))
    
    seg = SegTree(op, e(), q)
    outs = []
    
    for t, s, x, y in queries:
        diff = x - y if s == 1 else y - x
        p = bisect.bisect_left(tmp, (diff, s, x, y))
        if t == 1:
            if cnt[p] == 0:
                if s == 1: seg.set(p, (inf, x, y, inf, inf))
                else: seg.set(p, (inf, inf, inf, x, y))
            cnt[p] += 1
        else:
            cnt[p] -= 1
            if cnt[p] == 0:
                seg.set(p, (inf, inf, inf, inf, inf))
        
        ans = seg.all_prod()[0]
        outs.append(ans if ans < inf else -1)
    
    print('\n'.join(map(str, outs)))