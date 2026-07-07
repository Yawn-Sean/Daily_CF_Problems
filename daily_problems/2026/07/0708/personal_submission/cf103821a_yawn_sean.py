# Submission link: https://codeforces.com/gym/103821/submission/381552797
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        tmp = [[] for _ in range(n)]
        
        for i in range(q):
            x1, x2, y = MII()
            x1 -= 1
            x2 -= 1
            tmp[y].append((x1, x2))
        
        seg = SegTree(fmax, 0, [1] * n)
        
        for i in range(n):
            for l, r in tmp[i]:
                if seg.prod(l, r + 1):
                    while True:
                        p = seg.max_right(l, lambda x: x == 0)
                        if p <= r: seg.set(p, 0)
                        else: break
                    seg.set(l, 1)
                    seg.set(r, 1)
        
        outs.append(sum(seg.get(i) for i in range(n)))
    
    print('\n'.join(map(str, outs)))