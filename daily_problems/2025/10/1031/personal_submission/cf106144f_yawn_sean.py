# Submission link: https://codeforces.com/gym/106144/submission/346623865
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        c0 = 0
        c1 = 0
        
        for _ in range(n):
            s = I()
            if 'xxx' in s: c1 ^= 1
            elif 'xx' in s: c0 ^= 1
        
        outs.append('Monocarp' if c1 or c1 else 'Polycarp')
    
    print('\n'.join(outs))