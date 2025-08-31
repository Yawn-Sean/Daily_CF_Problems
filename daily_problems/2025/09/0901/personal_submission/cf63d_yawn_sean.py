# Submission link: https://codeforces.com/contest/63/submission/336386524
def main():
    a, b, c, d, n = MII()
    nums = LII()

    N = fmax(b, d)
    M = a + c

    grid = [[-1] * M for _ in range(N)]

    for i in range(b):
        for j in range(a):
            grid[i][j] = -2

    for i in range(d):
        for j in range(c):
            grid[i][a + j] = -2

    if a % 2:
        x, y = b - 1, 0
        dx = -1
    else:
        x, y = 0, 0
        dx = 1

    pt = 0

    for i in range(a * b + c * d):
        if i:
            if 0 <= x + dx < N and grid[x + dx][y] == -2:
                x += dx
            else:
                y += 1
                dx = -dx
        
        while nums[pt] == 0:
            pt += 1
        nums[pt] -= 1
        
        grid[x][y] = pt

    print('YES')
    print('\n'.join(''.join('.' if x == -1 else chr(ord('a') + x) for x in line) for line in grid))