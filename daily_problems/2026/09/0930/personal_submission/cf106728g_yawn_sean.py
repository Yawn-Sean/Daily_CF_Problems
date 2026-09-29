# Submission link: https://codeforces.com/gym/106728/submission/392579069
def main():
    n = II()
    hs = LII()
    vs = LII()
    
    hs.sort()
    
    cnt = [0] * n
    for x in vs:
        cnt[x] += 1
    
    for i in range(n - 2, -1, -1):
        cnt[i] += cnt[i + 1]
    
    for i in range(n):
        cnt[i] -= n - i
    
    if max(cnt) > 0: print(-1)
    else:
        seg = LazySegTree(fmax, 0, add, add, 0, cnt)
        fen = FenwickTree([1] * n)
        
        ans = [0] * n
    
        for i in range(n):
            seg.apply(0, n - i, 1)
            p = fmax(seg.min_left(n - i, lambda x: x <= 0) - 1, 0)
            seg.apply(0, p + 1, -1)
            
            target_idx = fen.bisect_min_larger(p + 1)
            fen.add(target_idx, -1)
            ans[i] = hs[target_idx]
    
        print(' '.join(map(str, ans)))