# Submission link: https://codeforces.com/gym/101875/submission/337901432
def main():
    n = II()
    xs = []
    vs = []
    
    for _ in range(n):
        x, v = MII()
        xs.append(x)
        vs.append(v)
    
    st_range = sorted(range(n), key=lambda x: -xs[x])
    
    stk_x = []
    stk_v = []
    
    ans = 0
    
    for i in st_range:
        x, v = xs[i], vs[i]
        
        while len(stk_x):
            if stk_v[-1] >= v: 
                stk_x.pop()
                stk_v.pop()
            elif len(stk_x) > 1:
                x1, v1 = stk_x[-1], stk_v[-1]
                x2, v2 = stk_x[-2], stk_v[-2]
                
                if (v - v2) * (x - x1) <= (v - v1) * (x - x2):
                    stk_x.pop()
                    stk_v.pop()
                else:
                    break
            else:
                break
        
        if len(stk_x):
            x1, v1 = stk_x[-1], stk_v[-1]
            ans = fmax(ans, -(x - x1) / (v - v1))
    
        stk_x.append(x)
        stk_v.append(v)
    
    print(ans)