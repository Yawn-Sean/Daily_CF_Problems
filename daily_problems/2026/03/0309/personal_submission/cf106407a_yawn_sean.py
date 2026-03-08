# Submission link: https://codeforces.com/gym/106407/submission/365853062
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, k = MII()
        
        if k == 1: outs.append('Munir' if n * m % 2 else 'Matthew')
        elif n % 2 or m % 2 or k >= 4: outs.append('Munir')
        else: outs.append('Matthew')
    
    print('\n'.join(outs))