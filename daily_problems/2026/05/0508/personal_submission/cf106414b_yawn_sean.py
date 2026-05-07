# Submission link: https://codeforces.com/gym/106414/submission/373788850
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        
        outs.append('NO' if min(s) == max(s) or (n == 3 and len(set(s)) == 3) else 'YES')
    
    print('\n'.join(outs))