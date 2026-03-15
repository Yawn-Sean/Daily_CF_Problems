# Submission link: https://codeforces.com/gym/106259/submission/366809889
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, r1, c1, r2, c2 = MII()
        
        if n % 2 and m % 2: outs.append('NO')
        elif fmin(n, m) == 1:
            if m == 1:
                n, m = m, n
                r1, c1 = c1, r1
                r2, c2 = c2, r2
            if c1 > c2: c1, c2 = c2, c1
            if (c1 - 1) % 2 or (c2 - c1 - 1) % 2 or (m - c2) % 2:
                outs.append('NO')
            else:
                outs.append('YES')
        elif (r1 + c1) % 2 == (r2 + c2) % 2: outs.append('NO')
        else: outs.append('YES')
    
    print('\n'.join(map(str, outs)))