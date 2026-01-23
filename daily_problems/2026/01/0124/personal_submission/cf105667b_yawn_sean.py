# Submission link: https://codeforces.com/gym/105667/submission/359339028
def main(): 
    n, m = MII()
    grid = [LII() for _ in range(n)]
    
    acc_13 = [[0] * (m + 1) for _ in range(n + 1)]
    acc_22 = [[0] * (m + 1) for _ in range(n + 1)]
    acc_31 = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(n):
        for j in range(m - 2):
            if grid[i][j] == grid[i][j + 1] and grid[i][j] == grid[i][j + 2]:
                acc_13[i + 1][j + 1] = 1
    
    for i in range(n - 1):
        for j in range(m - 1):
            if grid[i][j] == grid[i][j + 1] and grid[i][j] == grid[i + 1][j] and grid[i][j] == grid[i + 1][j + 1]:
                acc_22[i + 1][j + 1] = 1
    
    for i in range(n - 2):
        for j in range(m):
            if grid[i][j] == grid[i + 1][j] and grid[i][j] == grid[i + 2][j]:
                acc_31[i + 1][j + 1] = 1
    
    for i in range(n + 1):
        for j in range(m):
            acc_13[i][j + 1] += acc_13[i][j]
            acc_22[i][j + 1] += acc_22[i][j]
            acc_31[i][j + 1] += acc_31[i][j]
    
    for i in range(n):
        for j in range(m + 1):
            acc_13[i + 1][j] += acc_13[i][j]
            acc_22[i + 1][j] += acc_22[i][j]
            acc_31[i + 1][j] += acc_31[i][j]
    
    q = II()
    outs = []
    
    for _ in range(q):
        x1, y1, x2, y2 = MII()
        
        flg = True
        
        if y2 >= y1 + 2 and acc_13[x1][y1] - acc_13[x2 + 1][y1] - acc_13[x1][y2 - 1] + acc_13[x2 + 1][y2 - 1]:
            flg = False
        
        if x2 > x1 and y2 > y1 and acc_22[x1][y1] - acc_22[x2][y1] - acc_22[x1][y2] + acc_22[x2][y2]:
            flg = False
        
        if x2 >= x1 + 2 and acc_31[x1][y1] - acc_31[x2 - 1][y1] - acc_31[x1][y2 + 1] + acc_31[x2 - 1][y2 + 1]:
            flg = False
        
        outs.append('YES' if flg else 'NO')
    
    print('\n'.join(outs))