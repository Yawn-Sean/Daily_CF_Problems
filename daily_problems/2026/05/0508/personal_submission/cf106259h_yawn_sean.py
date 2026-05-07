# Submission link: https://codeforces.com/gym/106259/submission/373789774
def main(): 
    M = 10 ** 7
    is_prime = [1] * M
    
    is_prime[0] = 0
    is_prime[1] = 0
    
    for i in range(2, M):
        if is_prime[i]:
            for j in range(i * 2, M, i):
                is_prime[j] = 0
    
    chosen = [0] * M
    twins = []
    
    for i in range(M - 2):
        if is_prime[i] and is_prime[i + 2] and not chosen[i]:
            chosen[i] = 1
            chosen[i + 2] = 1
            twins.append(i)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        
        outs.append(str(4 + (n + 3) // 4))
        outs.append('-2 -2')
        outs.append('-2 0')
        outs.append('0 0')
        outs.append('0 -2')
        
        for i in range((n + 3) // 4):
            outs.append(f'{twins[i * 2]} {twins[i * 2 + 1]}')
        
        for i in range(n):
            outs.append(f'{i % 4 + 1} {(i + 1) % 4 + 1} {i // 4 + 5}')
    
    print('\n'.join(outs))