'''
https://codeforces.com/problemset/submission/581/299323167
581D
2025/1/2 Y1
1700
分类讨论
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    return x1, y1, x2, y2, x3, y3

def solve(x1, y1, x2, y2, x3, y3):
    for _ in range(2):
        x1, y1 = y1, x1
        for _ in range(2):
            x2, y2 = y2, x2
            for _ in range(3):
                x3, y3 = y3, x3
                if y1 == y2 == y3 and x1 + x2 + x3 == y1:
                    grid = [[''] * y1 for _ in range(y1)]
                    for i in range(x1):
                        for j in range(y1):
                            grid[i][j] = 'A'
                    for i in range(x1, x1 + x2):
                        for j in range(y1):
                            grid[i][j] = 'B'
                    for i in range(x1 + x2, x1 + x2 + x3):
                        for j in range(y1):
                            grid[i][j] = 'C'
                    return grid
                if y1 == y2 + y3 and x2 == x3 and x1 + x2 == y1:
                    grid = [[''] * y1 for _ in range(y1)]
                    for i in range(x1):
                        for j in range(y1):
                            grid[i][j] = 'A'
                    for i in range(x1, x1 + x2):
                        for j in range(y2):
                            grid[i][j] = 'B'
                    for i in range(x1, x1 + x2):
                        for j in range(y2, y2 + y3):
                            grid[i][j] = 'C'
                    return grid
                if y2 == y1 + y3 and x1 == x3 and x1 + x2 == y2:
                    grid = [[''] * y2 for _ in range(y2)]
                    for i in range(x2):
                        for j in range(y2):
                            grid[i][j] = 'B'
                    for i in range(x2, x1 + x2):
                        for j in range(y1):
                            grid[i][j] = 'A'
                    for i in range(x2, x1 + x2):
                        for j in range(y1, y1 + y3):
                            grid[i][j] = 'C'
                    return grid
                if y3 == y1 + y2 and x1 == x2 and x1 + x3 == y3:
                    grid = [[''] * y3 for _ in range(y3)]
                    for i in range(x3):
                        for j in range(y3):
                            grid[i][j] = 'C'
                    for i in range(x3, x1 + x3):
                        for j in range(y1):
                            grid[i][j] = 'A'
                    for i in range(x3, x1 + x3):
                        for j in range(y1, y1 + y2):
                            grid[i][j] = 'B'
                    return grid
    return []

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print(len(ans))
        print(*(''.join(r) for r in ans), sep='\n')
    else:
        print(-1)
