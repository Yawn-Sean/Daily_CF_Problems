# Submission link: https://codeforces.com/gym/105873/submission/375959036
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, A = MII()
        
        if 2 * A < n - 2: outs.append('No')
        else:
            outs.append('Yes')
            
            line0 = [(0, -2 * A + n - 2)] if n % 2 == 0 else [(2, -2 * A + n - 3), (0, 0)]
            line1 = [(1, 0)]
            
            for i in range(1, n // 2):
                line0.append((i % 2 - 1, i))
                line1.append((i % 2, i))
            
            line0.extend(reversed(line1))
            
            outs.append('\n'.join(f'{x} {y}' for x, y in line0))
    
    print('\n'.join(outs))