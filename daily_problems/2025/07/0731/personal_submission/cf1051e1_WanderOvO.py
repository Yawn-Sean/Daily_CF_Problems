"""
枚举中心，枚举大小，可以则涂最大的那个，在另一个网格中标记
最后看两个网格是否一样
"""

n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(input())

res = [['.' for _ in range(m)] for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def out_of_bound(x, y):
    return not (0 <= x < n and 0 <= y < m)

outs = []
for i in range(n):
    for j in range(m):
        if grid[i][j] == '*':
            max_len = -1
            for l in range(1, n):
                ok = True
                for k in range(4):
                    if out_of_bound(i + l * dx[k], j + l * dy[k]):
                        ok = False
                        break
                    if grid[i + l * dx[k]][j + l * dy[k]] == '.':
                        ok = False
                        break
                if ok:
                    max_len = max(max_len, l)
                else:
                    break
            if max_len > 0:
                outs.append((i + 1, j + 1, max_len))
                for k in range(i - max_len, i + max_len + 1):
                    res[k][j] = '*'
                for k in range(j - max_len, j + max_len + 1):
                    res[i][k] = '*'

all_the_same = True
for i in range(n):
    for j in range(m):
        if grid[i][j] != res[i][j]:
            all_the_same = False
            break
if all_the_same:
    print(len(outs))
    for i in range(len(outs)):
        for j in range(3):
            print(outs[i][j], end=' ')
        print()
else:
    print(-1)
