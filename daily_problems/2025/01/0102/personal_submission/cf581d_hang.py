# 三个长条拼在一起。
# 一个长条放在最上面，剩下两个拼成下面（上面的长条有三种可能）。
# https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2025/01/0102/solution/cf581d.md

def main():
    x1, y1, x2, y2, x3, y3 = map(int, input().split())

    for _ in range(2):
        x1, y1 = y1, x1
        for _ in range(2):
            x2, y2 = y2, x2
            for _ in range(3):
                x3, y3 = y3, x3
                if y1 == y2 == y3 and x1 + x2 + x3 == y1:
                    print(y1)
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
                    print('\n'.join(''.join(x) for x in grid))
                    return
                if y1 == y2 + y3 and x2 == x3 and x1 + x2 == y1:
                    print(y1)
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
                    print('\n'.join(''.join(x) for x in grid))
                    return
                if y2 == y1 + y3 and x1 == x3 and x1 + x2 == y2:
                    print(y2)
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
                    print('\n'.join(''.join(x) for x in grid))
                    return
                if y3 == y1 + y2 and x1 == x2 and x1 + x3 == y3:
                    print(y3)
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
                    print('\n'.join(''.join(x) for x in grid))
                    return

    print(-1)

main()