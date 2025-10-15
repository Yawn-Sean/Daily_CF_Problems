# Submission link: https://codeforces.com/contest/585/submission/331093153
def main():
    n = II()
    vs = []
    ds = []
    ps = []
    
    for _ in range(n):
        v, d, p = MII()
        vs.append(v)
        ds.append(d)
        ps.append(p)
    
    ans = []
    to_decide = [0] * n
    
    for i in range(n):
        if to_decide[i] == 0:
            ans.append(i)
            v = vs[i]
            
            for j in range(i + 1, n):
                if not to_decide[j] and v:
                    ps[j] -= v
                    v -= 1
            
            cur = 0
            for j in range(i + 1, n):
                ps[j] -= cur
                if not to_decide[j] and ps[j] < 0:
                    to_decide[j] = 1
                    cur += ds[j]
    
    print(len(ans))
    print(' '.join(str(x + 1) for x in ans))