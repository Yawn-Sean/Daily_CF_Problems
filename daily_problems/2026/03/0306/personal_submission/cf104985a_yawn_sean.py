# Submission link: https://codeforces.com/gym/104985/submission/365479773
def main(): 
    n = II()
    vs = []
    ts = []
    
    for _ in range(n):
        v, t = MII()
        vs.append(v)
        ts.append(t)
    
    st_range = sorted(range(n), key=lambda x: ts[x])
    total_v = sum(vs)
    
    res = 0
    
    cur_t = 0
    cur_v = total_v
    
    ans = [0] * n
    
    for i in st_range:
        res += (ts[i] - cur_t) * cur_v / total_v
        cur_t = ts[i]
        cur_v -= vs[i]
        ans[i] = res
    
    print('\n'.join(map(str, ans)))