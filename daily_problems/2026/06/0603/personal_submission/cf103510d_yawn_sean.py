# Submission link: https://codeforces.com/gym/103150/submission/376977664
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, d = MII()
        
        if (n // 2) * (n // 2) * 2 >= d:
            outs.append('YES')
            
            x = n // 2 * 2
            for i in range(x):
                for j in range(x):
                    outs.append(f'{i + 1} {j + 1} {(i + x // 2) % x + 1} {(j + x // 2) % x + 1}')
            
            if n % 2:
                for i in range(1, n + 1):
                    outs.append(f'{i} {n} {n} {n + 1 - i}')
                
                for i in range(1, n):
                    outs.append(f'{n} {i} {n - i} {n}')
        else:
            outs.append('NO')
    
    print('\n'.join(outs))