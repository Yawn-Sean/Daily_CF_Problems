# Submission link: https://codeforces.com/gym/106164/submission/374157997
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        if n == 2:
            if m % 2: outs.append('2 1')
            else: outs.append('1 2')
        else:
            m = fmin(n, m)
            ans = []
            
            for i in range(m):
                ans.append(n - i)
            
            for i in range(n - m):
                ans.append(i + 1)
            
            outs.append(' '.join(map(str, ans)))
    
    print('\n'.join(outs))