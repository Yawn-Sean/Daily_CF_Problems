# Submission link: https://codeforces.com/gym/105141/submission/399978827
def main(): 
    n, s0, w0 = MII()
    
    M = 10 ** 5
    total = [0] * (M + 1)
    cnt = [0] * (M + 1)
    
    ss = []
    ws = []
    ds = []
    
    for _ in range(n):
        s, w, d = MII()
        ss.append(s)
        ws.append(w)
        ds.append(d)
        
        total[d] += d
        cnt[d] += 1
    
    for i in range(1, M + 1):
        total[i] += total[i - 1]
        cnt[i] += cnt[i - 1]
    
    cnt0 = cnt[s0] + 1
    l, r = 1, w0 - total[s0]
    
    for i in range(n):
        cur = total[ss[i]]
        cur_cnt = cnt[ss[i]]
        
        if ds[i] > ss[i]:
            cur += ds[i]
            cur_cnt += 1
        
        if ws[i] >= cur:
            if cur_cnt >= cnt0:
                l = fmax(ws[i] - cur + 1, l)
                r = fmin(r, ss[i])
    
            elif cur_cnt == cnt0 - 1:
                l = fmax(l, fmin(ws[i] - cur + 1, ss[i] + 1))
    
    print('Yes' if l <= r else 'No')