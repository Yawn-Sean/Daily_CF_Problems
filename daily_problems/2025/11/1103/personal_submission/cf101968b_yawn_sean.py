# Submission link: https://codeforces.com/gym/101968/submission/347061297
def main(): 
    mod = 10 ** 9 + 7
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        xs = []
        ys = []
        
        for _ in range(n * 2):
            x, y = MII()
            xs.append(x)
            ys.append(y)
        
        vxs = sorted(xs)
        vys = sorted(ys)
        
        if vxs[n] == vxs[n - 1] or vys[n] == vys[n - 1]:
            outs.append(0)
        else:
            v1 = 0
            v2 = 0
            ans = 1
            for i in range(n * 2):
                if xs[i] < vxs[n]:
                    if ys[i] < vys[n]:
                        v1 += 1
                        ans = ans * v1 % mod
                    else:
                        v2 += 1
                        ans = ans * v2 % mod
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))