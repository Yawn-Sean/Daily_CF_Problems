# Submission link: https://codeforces.com/gym/106069/submission/399213724
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        x, y, n = MII()
        
        total = x + 2 * y
        
        if total % n == 0:
            w = total // n
            
            if w % 2 * n <= x:
                outs.append('0')
                continue
        
        else:
            w, v = divmod(total, n)
            
            if w % 2 * (n - v) + (w + 1) % 2 * v <= x:
                outs.append('1')
                continue
        
        outs.append('2')
    
    print('\n'.join(outs))