# Submission link: https://codeforces.com/gym/106632/submission/385363885
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        outs.append('YES')
    
        for i in range(1, n + 1):
            outs.append(' '.join(str((i + j) * (i + j + 1)) for j in range(m)))
    
    print('\n'.join(outs))