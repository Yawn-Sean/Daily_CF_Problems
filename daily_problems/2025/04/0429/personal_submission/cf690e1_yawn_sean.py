# Submission link: https://codeforces.com/problemset/submission/690/317684154
def main():
    q = II()
    outs = []

    for _ in range(q):
        h, w = MII()
        grid = [LII() for _ in range(h)]
        
        res1 = res2 = 0
        
        for i in range(w):
            res1 += abs(grid[0][i] - grid[-1][i])
            res2 += abs(grid[h // 2][i] - grid[h // 2 - 1][i])
        
        if res1 > res2: outs.append('NO')
        else: outs.append('YES')

    print('\n'.join(outs))