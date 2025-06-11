def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        grid = [list(map(int, I())) for _ in range(n)]
        cnt1 = [0] * n
        cnt2 = [0] * m
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    cnt1[i] += 1
                    cnt2[j] += 1 
        
        if cnt1[0] == 0 or cnt1[-1] == 0 or cnt2[0] == 0 or cnt2[-1] == 0:
            outs.append('-1')
        elif sum(cnt1) == n * m:
            outs.append('0')
        elif (grid[0][0] and grid[-1][-1]) or (grid[0][-1] and grid[-1][0]):
            outs.append('1')
        elif grid[0][0] or grid[-1][0] or grid[0][-1] or grid[-1][-1]:
            outs.append('2')
        else:
            outs.append('3')
    
    print('\n'.join(outs))