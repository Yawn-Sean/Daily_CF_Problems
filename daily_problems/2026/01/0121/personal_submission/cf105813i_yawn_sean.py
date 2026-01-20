# Submission link: https://codeforces.com/gym/105813/submission/358685880
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        a, b, n = MII()
        
        if n > a + 2 * (2 * b - 1): outs.append('Bob')
        elif n <= a + 2 * (b - 1): outs.append('Alice')
        elif n < 3 * a: outs.append('Bob')
        else: outs.append('Alice')
    
    print('\n'.join(map(str, outs)))