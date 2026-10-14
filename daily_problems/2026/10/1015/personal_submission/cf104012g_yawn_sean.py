# Submission link: https://codeforces.com/gym/104012/submission/394465017
def main():
    n, q = MII()
    
    def f(x, y):
        return x if y == 0 else f(y, x // y)
    
    tmp = [[] for _ in range(n + 1)]
    
    for i in range(2, n + 1):
        for j in range(1, n // i + 1):
            g = f(i, j)
            
            if i % g == 0:
                l = i * j
                r = fmin(i * (j + 1), n + 1)
                
                for v in range(((l - 1) // g + 1) * g, r, g):
                    if math.gcd(v, i) == g:
                        tmp[v].append(i)
    
    res = []
    
    for i in range(n + 1):
        for j in tmp[i]:
            res.append(i * (n + 1) + j)
    
    outs = []
    
    for _ in range(q):
        p = II()
        
        if p <= len(res):
            x, y = divmod(res[p - 1], n + 1)
            outs.append(f'{x} {y}')
        else:
            outs.append('-1 -1')
    
    print('\n'.join(outs))