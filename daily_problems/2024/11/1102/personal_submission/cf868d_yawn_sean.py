# Submission link: https://codeforces.com/contest/868/submission/289339572
def main():
    n = II()
    strs = [I() for _ in range(n)]
    m = II()

    pres = [''] * (n + m)
    sufs = [''] * (n + m)
    vis = [[0] * 1024 for _ in range(n + m)]

    for i in range(n):
        pres[i] = strs[i][:10]
        sufs[i] = strs[i][-10:]
        
        k = len(strs[i])
        for l in range(k):
            cur = 0
            for r in range(l, l + 10):
                if r >= k: break
                cur = cur * 2 + int(strs[i][r])
                vis[i][cur] |= 1 << r - l

    outs = [0] * m
    for i in range(n, n + m):
        a, b = GMI()

        for j in range(1024):
            vis[i][j] |= vis[a][j] | vis[b][j]
        
        for j in range(1, len(sufs[a]) + 1):
            cur = 0
            for k in range(j, 0, -1):
                cur = cur * 2 + int(sufs[a][-k])
            for k in range(len(pres[b])):
                if j + k >= 10: break
                cur = cur * 2 + int(pres[b][k])
                vis[i][cur] |= 1 << j + k
        
        if len(pres[a]) == 10: pres[i] = pres[a]
        else: pres[i] = (pres[a] + pres[b])[:10]
        
        if len(sufs[b]) == 10: sufs[i] = sufs[b]
        else: sufs[i] = (sufs[a] + sufs[b])[-10:]

        for v in range(1, 11):
            flg = True
            for msk in range(1 << v):
                if vis[i][msk] >> (v - 1) & 1 == 0:
                    flg = False
            if flg: outs[i - n] = v
            else: break
        
    print('\n'.join(map(str, outs)))