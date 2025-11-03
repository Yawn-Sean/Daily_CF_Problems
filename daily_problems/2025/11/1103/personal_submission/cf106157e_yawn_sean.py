# Submission link: https://codeforces.com/gym/106157/submission/347056849
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        m, t = MII()
        
        if t <= 3 * m: outs.append(0)
        else:
            l, r = 3, t // m
            
            def f(x):
                side = (t / x - m) / 2
                return side * side / math.tan(math.pi / x) * x
            
            while l < r:
                mid = (l + r) // 2
                if f(mid) < f(mid + 1):
                    l = mid + 1
                else:
                    r = mid
            
            outs.append(f(l))
    
    print('\n'.join(map(str, outs)))