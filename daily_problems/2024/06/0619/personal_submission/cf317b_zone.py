def main(ac=FastIO()):
    n, t = ac.read_list_ints()
    
    grid = [[0] * 151 for _ in range(151)]
    grid[75][75] = n 
 
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
 
    while True:
        flag = True 
 
        for i in range(151):
            for j in range(151):
                # print(grid)
                if grid[i][j] >= 4:
                    v, grid[i][j] = divmod(grid[i][j], 4)
                    flag = False 
                    for di, dj in dirs:
                        grid[i + di][j + dj] += v 
        if flag: break 
    
    
    outs = []
    for _ in range(t):
        x, y = ac.read_list_ints()
        if abs(x) > 75 or abs(y) > 75: 
            outs.append(0)
            continue
        x += 75 
        y += 75 
        outs.append(grid[x][y])
    ac.flatten(outs)
