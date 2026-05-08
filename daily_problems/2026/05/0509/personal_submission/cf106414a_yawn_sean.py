# Submission link: https://codeforces.com/gym/106414/submission/373883372
def main(): 
    t = II()
    outs = []
    
    def f(x1, x2):
        x = abs(x1 - x2)
        if x == 0: return x
        return (x - 1) % 2 + 1
    
    for _ in range(t):
        n, m = MII()
        r1, c1, r2, c2 = MII()
        outs.append(f(r1, r2) + f(c1, c2))
    
    print('\n'.join(map(str, outs)))