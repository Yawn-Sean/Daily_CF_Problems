# Submission link: https://codeforces.com/gym/106197/submission/390674166
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        grid = [I() for _ in range(n)]
        
        pos_h = [-1] * n
        pos_v = [-1] * n
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 'H':
                    pos_h[i] = j
                else:
                    pos_v[j] = i
        
        outs.append(f'{n}')
        
        if min(pos_h) == -1:
            for i in range(n):
                outs.append(f'{pos_v[i] + 1} {i + 1}')
        else:
            for i in range(n):
                outs.append(f'{i + 1} {pos_h[i] + 1}')
    
    print('\n'.join(outs))