def main():
    n, k, M = MII()
    ts = LII()
    
    ts.sort()
    acc = sum(ts)
    ans = 0
    for cnt_complete in range(n + 1):
        require = cnt_complete * acc
        surplus = M - require
        if surplus < 0: continue
        cur_score = cnt_complete * (k + 1)
        for j in range(k):
            can = fmin(n - cnt_complete, surplus // ts[j])
            if can <= 0: break
            cur_score += can
            surplus -= ts[j] * can
    
        ans = fmax(cur_score, ans)
    
    print(ans)
