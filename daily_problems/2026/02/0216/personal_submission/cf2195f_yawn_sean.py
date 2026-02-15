# Submission link: https://codeforces.com/contest/2195/submission/363222619
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        xs = []
        ys = []
        zs = []
        
        for _ in range(n):
            x, y, z = MII()
            xs.append(x)
            ys.append(y)
            zs.append(z)
        
        st_range = sorted(range(n), key=lambda x: zs[x])
        
        dp_pref = [1] * n
        
        for i in range(n):
            for j in range(i):
                vi = st_range[i]
                vj = st_range[j]
                
                if xs[vi] == xs[vj]:
                    if ys[vi] == ys[vj]:
                        dp_pref[vi] = fmax(dp_pref[vi], dp_pref[vj] + 1)
                else:
                    a = xs[vi] - xs[vj]
                    b = ys[vi] - ys[vj]
                    c = zs[vi] - zs[vj]
                    
                    if b * b < 4 * a * c:
                        dp_pref[vi] = fmax(dp_pref[vi], dp_pref[vj] + 1)
        
        dp_suff = [1] * n
        
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                vi = st_range[i]
                vj = st_range[j]
                
                if xs[vi] == xs[vj]:
                    if ys[vi] == ys[vj]:
                        dp_suff[vi] = fmax(dp_suff[vi], dp_suff[vj] + 1)
                else:
                    a = xs[vi] - xs[vj]
                    b = ys[vi] - ys[vj]
                    c = zs[vi] - zs[vj]
                    
                    if b * b < 4 * a * c:
                        dp_suff[vi] = fmax(dp_suff[vi], dp_suff[vj] + 1)
        
        outs.append(' '.join(str(x + y - 1) for x, y in zip(dp_pref, dp_suff)))
    
    print('\n'.join(map(str, outs)))