# Submission link: https://codeforces.com/gym/106644/submission/387338757
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        
        if n % 2:
            outs.append('Doludu' if s[n // 2 - 1:n // 2 + 1] == 'BB' or s[n // 2:n // 2 + 2] == 'BB' else 'DoIudu')
        else:
            outs.append('Doludu' if 'B' in s[n // 2 - 1:n // 2 + 1] else 'DoIudu')
    
    print('\n'.join(outs))