# Submission link: https://codeforces.com/contest/815/submission/322916884
def main():
    n, m = MII()
    grid = [LII() for _ in range(n)]

    flg = True
    for i in range(n):
        for j in range(m):
            if grid[0][0] + grid[i][j] != grid[i][0] + grid[0][j]:
                flg = False

    if not flg:
        print(-1)
    else:
        v = min(grid[0]) if n < m else grid[0][0] - min(grid[i][0] for i in range(n))
        outs = []
        
        for _ in range(v):
            outs.append(f'row 1')
        
        for _ in range(grid[0][0] - v):
            outs.append(f'col 1')
        
        for i in range(1, n):
            for _ in range(grid[i][0] - (grid[0][0] - v)):
                outs.append(f'row {i + 1}')
        
        for i in range(1, m):
            for _ in range(grid[0][i] - v):
                outs.append(f'col {i + 1}')
        
        print(len(outs))
        print('\n'.join(outs))