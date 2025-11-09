# Submission link: https://codeforces.com/gym/106179/submission/348162522
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        c = II()
        x = c << 30
        outs.append(f'{x} {x ^ c}')
    
    print('\n'.join(outs))