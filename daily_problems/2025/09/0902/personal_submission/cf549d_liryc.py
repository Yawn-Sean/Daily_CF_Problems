'''
https://codeforces.com/problemset/submission/549/336567160
'''
# grid[i][j]: -1 for B and 1 for W
def solve(n: int, m: int, grid: list[list[int]]) -> int:
    ans = 0
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            c = grid[i][j]
            if i < n - 1: 
                c -= grid[i + 1][j]
            if j < m - 1: 
                c -= grid[i][j + 1]
            if i < n - 1 and j < m - 1: 
                c += grid[i + 1][j + 1]
            if c != 0: 
                ans += 1
    return ans
