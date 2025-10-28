"""
边长有单调性吗？
其实并不一定，比如边长为 3 可以，但是 2 就不一定可以
直接去枚举边长有点难搞
我们可能要找一条全是 # 的边，找最短的那个
然后，我们的正方形边长一定是 # 的因数，因数只有根号个，这样复杂度就可以接受了
"""

import sys

input = lambda: sys.stdin.readline().strip()

h, w = map(int, input().split())
grid = []
for i in range(h):
    s = input()
    row = []
    for ch in s:
        if ch == '#':
            row.append(1)
        else:
            row.append(0)
    grid.append(row)

min_side = max(h, w)
for i in range(h):
    j = 0
    while j < w:
        if grid[i][j] == 1:
            k = j
            while k < w and grid[i][k] == 1:
                k += 1
            min_side = min(min_side, k - j)
            j = k
        else:
            j += 1
for j in range(w):
    i = 0
    while i < h:
        if grid[i][j] == 1:
            k = i
            while k < h and grid[k][j] == 1:
                k += 1
            min_side = min(min_side, k - i)
            i = k
        else:
            i += 1

s = [[0 for _ in range(w + 1)]]
for i in range(h):
    row = [0]
    for j in range(w):
        row.append(grid[i][j])
    s.append(row)

for i in range(1, h + 1):
    for j in range(1, w + 1):
        s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]

def query(i, j, k, l):
    return s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1]

def check(side):
    i, j = 1, 1
    vis = [[False for _ in range(w + 1)] for _ in range(h + 1)]
    while i <= h:
        j = 1
        while j <= w:
            if grid[i - 1][j - 1] == 1 and not vis[i][j]:
                if i + side - 1 <= h and j + side - 1 <= w:
                    if query(i, j, i + side - 1, j + side - 1) != side * side:
                        return False
                    for k in range(i, i + side):
                        for l in range(j, j + side):
                            if vis[k][l]:
                                return False
                            vis[k][l] = True
                else:
                    return False
            j += 1
        i += 1
    return True

res = 1
for i in range(1, min_side + 1):
    if min_side % i == 0:
        if check(i):
            res = max(res, i)
print(res)
