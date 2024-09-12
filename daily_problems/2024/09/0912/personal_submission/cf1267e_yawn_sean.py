# Submission link: https://codeforces.com/contest/1267/submission/280791564
def main():
    n, m = MII()
    grid = [LII() for _ in range(m)]

    ans = 0
    idx = -1

    for i in range(n - 1):
        diff = [grid[j][n - 1] - grid[j][i] for j in range(m)]
        diff.sort()
        
        cur = 0
        for j in range(m):
            cur += diff[j]
            if cur > 0: break
            if j + 1 > ans:
                ans = j + 1
                idx = i

    print(m - ans)
    if ans == 0: print(' '.join(map(str, range(1, m + 1))))
    else:
        st_range = sorted(range(m), key=lambda x: grid[x][n - 1] - grid[x][idx])[ans:]
        print(' '.join(str(x + 1) for x in st_range))