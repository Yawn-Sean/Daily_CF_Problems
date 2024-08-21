"""
https://codeforces.com/contest/1468/submission/274467387
"""
def main():
    T = II() 
    outs = [] 
    for _ in range(T): 
        n, m, k = MII() 
        us, vs, ws = [], [], [] 
    
        p = list(range(n))
        def find(x):
            if x != p[x]: 
                p[x] = find(p[x])
            return p[x]
    
        ans = 10 ** 9 + 10
    
        for _ in range(m): 
            u, v, w = MII()
            us.append(u - 1)
            vs.append(v - 1)
            ws.append(w)
            ans = min(ans, abs(w - k))
        
        res = 0
        for u, v, w in sorted(zip(us, vs, ws), key=lambda x: x[-1]): 
            pu, pv = find(u), find(v)
            if pu != pv: 
                p[pu] = pv 
                res += max(0, w - k)
        outs.append(str(res) if res else str(ans))
    
    print('\n'.join(outs))
