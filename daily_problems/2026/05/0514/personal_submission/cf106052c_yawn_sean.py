# Submission link: https://codeforces.com/gym/106052/submission/374380303
def main():  
    M = 10 ** 6 + 5
    phi = list(range(M))
    
    for i in range(2, M):
        if phi[i] == i:
            for j in range(i, M, i):
                phi[j] = phi[j] // i * (i - 1)
    
    for i in range(2, M):
        if i % 2 == 0:
            phi[i] = 0
        else:
            phi[i] = 2 * phi[i]
    
    for i in range(1, M):
        phi[i] += phi[i - 1]
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ans = 0
        
        for i in range(1, n + 1):
            ans += phi[n // i]
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))