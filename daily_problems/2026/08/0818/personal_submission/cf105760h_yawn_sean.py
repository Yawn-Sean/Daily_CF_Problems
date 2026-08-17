# Submission link: https://codeforces.com/gym/105760/submission/387345843
def main():
    k, s, e = MII()
    
    emptys = [i for i in range(1, k + 1) if i != s and i != e]
    
    outs = []
    
    for i in range(k - 1, 0, -1):
        outs.append(f'{s} {e}')
        
        for j in range(i - 1):
            outs.append(f'{s} {emptys[k - 3 - j]}')
        
        for j in range(i - 3, -1, -1):
            outs.append(f'{emptys[k - 3 - j]} {emptys[k - 1 - i]}')
        
        if i > 1:
            outs.append(f'{e} {emptys[k - 1 - i]}')
    
    for i in range(k - 3, -1, -1):
        outs.append(f'{emptys[i]} {s}')
        
        for j in range(k - 3, i, -1):
            outs.append(f'{emptys[i]} {emptys[j]}')
        
        outs.append(f'{emptys[i]} {e}')
        
        for j in range(i + 1, k - 2):
            outs.append(f'{emptys[j]} {e}')
        
        outs.append(f'{s} {e}')
    
    print(2 * (k - 1) * (k - 1) - 1)
    print('\n'.join(outs))