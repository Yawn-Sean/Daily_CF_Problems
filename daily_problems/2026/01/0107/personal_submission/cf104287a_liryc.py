'''
Docstring for daily_problems.2026.01.0107.personal_submission.cf104287a_liryc
'''
def presolve(n: int, grid: list[list[int]]) -> list[list[int]]: 
    mr = [[n * n + 1] * (n * n + 1) for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i + k >= n or j + k >= n:
                    break
                mr[k][grid[i][j]] = min(mr[k][grid[i][j]], grid[i + k][j + k])
    for i in range(n):
        for j in range(n * n - 1, -1, -1):
            mr[i][j] = min(mr[i][j], mr[i][j + 1])
    return mr
    
def solve(n: int, mr: list[list[int]], a: int, b: int) -> int:
    for i in range(n - 1, -1, -1):
        if mr[i][a] <= b:
            return (i + 1) * (i + 1)
    