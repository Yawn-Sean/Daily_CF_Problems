# Submission link: https://codeforces.com/gym/106404/submission/365343827
def main(): 
    n, m = MII()
    grid = [LII() for _ in range(n)]
    
    acc = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                acc[i + 1][j + 1] = 1
    
    for i in range(n):
        for j in range(m + 1):
            acc[i + 1][j] += acc[i][j]
    
    for i in range(n + 1):
        for j in range(m):
            acc[i][j + 1] += acc[i][j]
    
    next_pos = [[m] * (m + 1) for _ in range(n)]
    
    for i in range(n):
        for j in range(m - 1, -1, -1):
            next_pos[i][j] = next_pos[i][j + 1]
            if grid[i][j]:
                next_pos[i][j] = j
    
    def calc(x1, y1, x2, y2):
        x2 += 1
        y2 += 1
        return acc[x1][y1] - acc[x1][y2] - acc[x2][y1] + acc[x2][y2]
    
    q = II()
    outs = []
    
    for _ in range(q):
        x1, y1, x2, y2 = GMI()
        
        pt = x1
        tmp = []
        while len(tmp) <= 30:
            l, r = pt, x2
            
            while l <= r:
                mid = (l + r) // 2
                if calc(pt, y1, mid, y2): r = mid - 1
                else: l = mid + 1
            
            if l > x2: break
            
            cur = y1
            while next_pos[l][cur] <= y2:
                cur = next_pos[l][cur]
                if len(tmp) > 30: break
                tmp.append(grid[l][cur])
                cur += 1
            
            pt = l + 1
        
        if len(tmp) > 30: outs.append('YES')
        else:
            tmp.sort()
            for i in range(2, len(tmp)):
                if tmp[i - 2] + tmp[i - 1] > tmp[i]:
                    outs.append('YES')
                    break
            else:
                outs.append('NO')
    
    print('\n'.join(outs))