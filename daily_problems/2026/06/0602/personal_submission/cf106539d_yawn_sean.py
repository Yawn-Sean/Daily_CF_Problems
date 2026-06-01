# Submission link: https://codeforces.com/gym/106539/submission/376890560
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        outs.append(fmin(n, m // 2 + 1))
    
    print('\n'.join(map(str, outs)))