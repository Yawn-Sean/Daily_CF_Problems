'''
https://codeforces.com/problemset/submission/690/317695912
'''
def solve(h: int, w: int, grid: list[list[int]]) -> bool:
    s1 = sum(abs(a - b) for a, b in zip(grid[0], grid[-1]))
    s2 = sum(abs(a - b) for a, b in zip(grid[h // 2], grid[h // 2 - 1]))
    return s1 <= s2    

