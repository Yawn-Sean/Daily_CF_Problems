# Submission link: https://codeforces.com/gym/101059/submission/391590895
def main():
    n, q = MII()
    v1 = LII()
    v2 = LII()
    
    ls = []
    rs = []
    ks = []
    
    for _ in range(q):
        l, r, k = MII()
        ls.append(l - 1)
        rs.append(r)
        ks.append(k)
    
    ans = [0] * q
    
    B = 320
    
    st_range = sorted(range(q), key=lambda x: (ls[x] // B, rs[x] if ls[x] // B % 2 else -rs[x]))
    
    M = 10 ** 5 + 1
    cnt1 = [0] * M
    fen1 = FenwickTree(M)
    cnt2 = [0] * M
    fen2 = FenwickTree(M)
    
    pl = 0
    pr = 0
    
    for i in st_range:
        l = ls[i]
        r = rs[i]
        k = ks[i]
        
        while pl > l:
            pl -= 1
            
            if v1[pl] < M:
                cnt1[v1[pl]] += 1
                fen1.add(v1[pl], 1)
            
            if v2[pl] < M:
                cnt2[v2[pl]] += 1
                fen2.add(v2[pl], 1)
        
        while pr < r:
            if v1[pr] < M:
                cnt1[v1[pr]] += 1
                fen1.add(v1[pr], 1)
            
            if v2[pr] < M:
                cnt2[v2[pr]] += 1
                fen2.add(v2[pr], 1)
            
            pr += 1
        
        while pl < l:
            if v1[pl] < M:
                cnt1[v1[pl]] -= 1
                fen1.add(v1[pl], -1)
            
            if v2[pl] < M:
                cnt2[v2[pl]] -= 1
                fen2.add(v2[pl], -1)
            
            pl += 1
        
        while pr > r:
            pr -= 1
            
            if v1[pr] < M:
                cnt1[v1[pr]] -= 1
                fen1.add(v1[pr], -1)
            
            if v2[pr] < M:
                cnt2[v2[pr]] -= 1
                fen2.add(v2[pr], -1)
        
        bound = math.isqrt(k)
        w1 = 0
        w2 = 0
        
        for cur in range(1, bound + 1):
            ans[i] += cnt1[cur] * fen2.rsum(0, k // cur)
            w1 += cnt1[cur]
            
            ans[i] += cnt2[cur] * fen1.rsum(0, k // cur)
            w2 += cnt2[cur]
        
        ans[i] -= w1 * w2
    
    print('\n'.join(map(str, ans)))