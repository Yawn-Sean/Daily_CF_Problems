# Submission link: https://codeforces.com/gym/105580/submission/376239689
def main():
    sys.setrecursionlimit(300000)
    
    n, m = MII()
    grid = [[set() for _ in range(2 * m + 1)] for _ in range(2 * n + 1)]
    
    dirs = [(0, -1), (0, 1), (-1, 0), (1, 0)]
    dir_str = ['LEFT', 'RIGHT', 'UP', 'DOWN']
    
    cur = [-1, -1, -1]
    
    def move(idx):
        if idx < 4: print('MOVE', dir_str[idx], flush=True)
        else: print('BACK', flush=True)
        ret = I()
        if ret == 'EXIT': exit()
        if ret == 'FAIL': return False
        return True
    
    def f(x, y):
        for i in range(4):
            if cur[-1] ^ i == 1: continue
            
            cur.append(i)
            dx, dy = dirs[i]
            nx = x + dx
            ny = y + dy
            
            if tuple(cur[-3:]) not in grid[nx][ny] and move(i):
                grid[nx][ny].add(tuple(cur[-3:]))
                f(nx, ny)
                move(4)
            
            cur.pop()
    
    f(n, m)