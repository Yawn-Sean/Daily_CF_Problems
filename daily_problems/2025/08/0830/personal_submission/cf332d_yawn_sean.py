# Submission link: https://codeforces.com/contest/332/submission/336198156
def main():
    n, k = MII()

    grid = [[-1] * n for _ in range(n)]

    for i in range(n - 1):
        nums = LII()
        
        for j in range(0, n - i - 1):
            grid[i][i + j + 1] = grid[i + j + 1][i] = nums[j]

    if k == 2:
        ans = 0
        
        for i in range(n):
            cnt = 0
            tot = 0
            
            for j in range(n):
                if grid[i][j] != -1:
                    cnt += 1
                    tot += grid[i][j]
            
            ans += (cnt - 1) * tot
        
        print(ans // (n * (n - 1) // 2))
    else:
        ans = 0
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] != -1:
                    ans += grid[i][j]

        print(ans // n)
