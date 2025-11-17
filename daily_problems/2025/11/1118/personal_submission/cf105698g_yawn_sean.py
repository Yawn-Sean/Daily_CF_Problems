# Submission link: https://codeforces.com/gym/105698/submission/349392038
def main(): 
    n, q = MII()
    seg = SegTree(fmin, n, [-1] * n)
    
    outs = []
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            l, r = query[1] - 1, query[2] - 1
            seg.set(l, fmax(seg.get(l), r))
        else:
            idx = query[1] - 1
            pos = seg.min_left(idx + 1, lambda x: x >= idx)
            outs.append(idx - pos + 2)
    
    print('\n'.join(map(str, outs)))