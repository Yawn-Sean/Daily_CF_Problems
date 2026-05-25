# Submission link: https://codeforces.com/gym/105873/submission/376007494
def main():
    n = II()
    ds = []
    ps = []
    cs = []
    lxs = []
    rxs = []
    lys = []
    rys = []
    
    for _ in range(n):
        d, p, c, lx, rx, ly, ry = MII()
        ds.append(d)
        ps.append(p)
        cs.append(c)
        lxs.append(lx)
        rxs.append(rx)
        lys.append(ly)
        rys.append(ry)
    
    dp = [0] * (1 << n)
    cur_time = [0] * (1 << n)
    
    for i in range(1, 1 << n):
        for j in range(n):
            if i >> j & 1:
                oi = i - (1 << j)
                cur_time[i] = cur_time[oi] + cs[j]
                
                nval = dp[oi]
                if cur_time[i] <= ds[j]:
                    nval += ps[j]
                    if cur_time[i] <= lys[j]:
                        nval += (lxs[j] + rxs[j]) / 2
                    elif cur_time[i] <= rys[j]:
                        nval += (lxs[j] + rxs[j]) / 2 * (rys[j] - cur_time[i]) / (rys[j] - lys[j])
                
                dp[i] = fmax(dp[i], nval)
    
    print(dp[-1])