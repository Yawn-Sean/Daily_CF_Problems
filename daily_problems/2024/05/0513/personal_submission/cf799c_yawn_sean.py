# Submission link: https://codeforces.com/contest/799/submission/260722473
def main():
    n, c, d = MII()

    bc = []
    pc = []

    bd = []
    pd = []

    for _ in range(n):
        b, p, v = LI()
        b = int(b)
        p = int(p)
        
        if v == 'C':
            bc.append(b)
            pc.append(p)
        
        else:
            bd.append(b)
            pd.append(p)

    kc = len(bc)
    kd = len(bd)

    ans = 0
    mc = md = -1
    for i in range(kc):
        if pc[i] <= c:
            mc = max(mc, bc[i])

    for i in range(kd):
        if pd[i] <= d:
            md = max(md, bd[i])

    if mc != -1 and md != -1:
        ans = mc + md

    def process(ps, bs, total):
        k = len(ps)
        
        st_range = sorted(range(k), key=lambda x: ps[x])
        ps = [ps[x] for x in st_range]
        bs = [bs[x] for x in st_range]
        bs_pref = bs[:]
        
        for i in range(1, k):
            bs_pref[i] = max(bs_pref[i-1], bs_pref[i])
        
        ans = 0
        for i in range(1, k):
            if ps[i] + ps[0] > total: break
            p = min(i - 1, bisect.bisect_right(ps, total - ps[i]) - 1)
            ans = max(ans, bs[i] + bs_pref[p])
        return ans

    print(max(ans, process(pc, bc, c), process(pd, bd, d)))