# Submission link: https://codeforces.com/gym/102254/submission/389672187
def main():
    M = 10 ** 6 + 5
    phi = list(range(M))
    
    for i in range(2, M):
        if phi[i] == i:
            for j in range(i, M, i):
                phi[j] = phi[j] // i * (i - 1)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        if math.gcd(n, m) > 1: outs.append('-1')
        else: outs.append(str(phi[m]))
    
    print('\n'.join(outs))