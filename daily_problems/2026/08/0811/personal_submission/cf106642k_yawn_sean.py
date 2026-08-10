# Submission link: https://codeforces.com/gym/106642/submission/386426997
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        grid = [[int(c) for c in I()] for _ in range(n)]
        
        c1 = [0] * n
        c2 = [0] * m
        
        for i in range(n):
            for j in range(m):
                c1[i] += grid[i][j]
                c2[j] += grid[i][j]
        
        cur = 0
        
        adds1 = [0] * n
        adds2 = [0] * m
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    cur += (c1[i] - 1) * (c2[j] - 1)
                    adds1[i] += c2[j] - 1
                    adds2[j] += c1[i] - 1
        
        ans = -1
        cnt = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    ncur = cur + c1[i] * c2[j] + adds1[i] + adds2[j]
                    
                    if ncur > ans:
                        ans = ncur
                        cnt = 1
                    elif ncur == ans:
                        cnt += 1
        
        outs.append(f'{ans} {cnt}')
    
    print('\n'.join(outs))