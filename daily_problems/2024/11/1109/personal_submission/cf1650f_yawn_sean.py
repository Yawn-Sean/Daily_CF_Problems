# Submission link: https://codeforces.com/contest/1650/submission/290618972
def main():
    t = II()
    outs = []

    inf = 2 * 10 ** 9

    for _ in range(t):
        n, m = MII()
        ddls = LII()
        
        ts = []
        ps = []
        
        to_finish = [[] for _ in range(n)]
        
        for i in range(m):
            e, t, p = MII()
            e -= 1
            to_finish[e].append(i)
            ts.append(t)
            ps.append(p)
        
        ans = []
        flg = True

        cur_time = 0
        
        for i in range(n):
            cnt = len(to_finish[i])
            
            dp = [inf] * 101
            pres = [[-1] * (cnt + 1) for _ in range(101)]
            dp[0] = 0
            
            for idx, oid in enumerate(to_finish[i]):
                for j in range(100, -1, -1):
                    if dp[j] < inf:
                        nj = fmin(j + ps[oid], 100)
                        
                        if dp[nj] > dp[j] + ts[oid]:
                            dp[nj] = dp[j] + ts[oid]
                            pres[nj][idx + 1] = oid * 101 + j
            
            if cur_time + dp[100] > ddls[i]:
                flg = False
                break
            
            cur_time += dp[100]
            cur = 100
            
            for j in range(cnt, 0, -1):
                if pres[cur][j] != -1:
                    oid, cur = divmod(pres[cur][j], 101)
                    ans.append(oid)
        
        if flg:
            outs.append(str(len(ans)))
            outs.append(' '.join(str(x + 1) for x in ans))
        else:
            outs.append('-1')

    print('\n'.join(map(str, outs)))