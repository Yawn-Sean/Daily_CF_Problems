# Submission link: https://codeforces.com/gym/106782/submission/395956084
def main():
    n, m = MII()
    
    ans = [['.'] * m for _ in range(n)]
    
    for i in range(1, n, 2):
        for j in range(1, m, 2):
            print('?', i + 1, j + 1, flush=True)
            ans[i][j] = I()
            
            if ans[i][j] == 'U': ans[i + 1][j] = 'D'
            elif ans[i][j] == 'D': ans[i - 1][j] = 'U'
            elif ans[i][j] == 'L': ans[i][j + 1] = 'R'
            else: ans[i][j - 1] = 'L'
    
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    chrs = 'URDL'
    degs = [[0] * m for _ in range(n)]
    
    stk = []
    
    for i in range(n):
        for j in range(m):
            if ans[i][j] != '.': continue
            for di, dj in dirs:
                if 0 <= i + di < n and 0 <= j + dj < m and ans[i + di][j + dj] == '.':
                    degs[i][j] += 1
            
            if degs[i][j] == 1: stk.append((i, j))
    
    while stk:
        x, y = stk.pop()
        
        if ans[x][y] == '.':
            for i in range(4):
                dx, dy = dirs[i]
                if 0 <= x + dx < n and 0 <= y + dy < m and ans[x + dx][y + dy] == '.':
                    ans[x][y] = chrs[i ^ 2]
                    ans[x + dx][y + dy] = chrs[i]
                    
                    degs[x][y] -= 1
                    degs[x + dx][y + dy] -= 1
                    
                    nx, ny = x + dx, y + dy
                    
                    for ndx, ndy in dirs:
                        if 0 <= nx + ndx < n and 0 <= ny + ndy < m and ans[nx + ndx][ny + ndy] == '.':
                            degs[nx + ndx][ny + ndy] -= 1
                            if degs[nx + ndx][ny + ndy] == 1:
                                stk.append((nx + ndx, ny + ndy))
    
    print('!')
    print('\n'.join(''.join(x) for x in ans))