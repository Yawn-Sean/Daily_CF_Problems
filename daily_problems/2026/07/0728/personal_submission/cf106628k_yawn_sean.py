# Submission link: https://codeforces.com/gym/106628/submission/384469352
def main():
    t = II()
    outs = []
    
    inf = 4 * 10 ** 9
    
    for _ in range(t):
        n = II()
        xs = []
        ys = []
        
        for _ in range(n):
            x, y = MII()
            xs.append(x - y)
            ys.append(x + y)
        
        if n <= 3: outs.append(0)
        else:
            st1 = sorted(range(n), key=lambda x: xs[x])
            st2 = sorted(range(n), key=lambda x: ys[x])
            
            idxs = st1[:2] + st1[-2:] + st2[:2] + st2[-2:]
            
            ans = inf
            
            for i in range(8):
                for j in range(i):
                    i1 = idxs[i]
                    i2 = idxs[j]
                    
                    mi_x = inf
                    ma_x = -inf
                    
                    mi_y = inf
                    ma_y = -inf
                    
                    for idx in range(n):
                        if idx != i1 and idx != i2:
                            mi_x = fmin(mi_x, xs[idx])
                            ma_x = fmax(ma_x, xs[idx])
                            
                            mi_y = fmin(mi_y, ys[idx])
                            ma_y = fmax(ma_y, ys[idx])
                    
                    ans = fmin(ans, fmax(ma_x - mi_x, ma_y - mi_y))
            
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))