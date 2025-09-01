'''
https://codeforces.com/problemset/submission/63/336445085
'''
# grid constructive
def solve(a: int, b: int, c: int, d: int, n: int, xa: list[int]) -> list[list[str]]:
    x, y, dx = 0, 0, 1
    if a & 1:
        x, dx = b - 1, -1
    h, w = max(b, d), a + c
    grid = [['.'] * w for _ in range(h)]
    i, nc, cc = 0, 0, '.'
    for _ in range(a * b + c * d):
        if nc == 0:
            nc, cc = xa[i], chr(97 + i)
            i += 1
        grid[x][y] = cc
        nc -= 1
        if x + dx < 0 or (y >= a and x + dx >= d or y < a and x + dx >= b):
            y, dx = y + 1, -dx
        else:
            x += dx
    return grid