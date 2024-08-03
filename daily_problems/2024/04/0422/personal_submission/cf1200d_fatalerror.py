"""
令W为0，B为1。利用二维滑动窗口、计算某一窗口位置下的全0行列数会超时。转而计算某一行列能变为全0所允许的窗口位置，这可以用二维差分解决。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, k = lii()
    grid = []
    for _ in range(n):
        grid.append([ch=='B' for ch in input()])

    base = 0
    diff = [[0] * (n-k+3) for _ in range(n-k+3)]
    for i, row in enumerate(grid):
        start, end = -1, -1
        for j, x in enumerate(row):
            if x:
                if start == -1: start = j
                end = j
        if start == -1:
            base += 1
            continue
        if end - start + 1 > k:
            continue
        l, r = max(0, end-k+1), min(n-1, start+k-1)-k+1
        t, b = max(0, i-k+1), min(n-1, i+k-1)-k+1
        diff[l+1][t+1] += 1
        diff[l+1][b+2] -= 1
        diff[r+2][t+1] -= 1
        diff[r+2][b+2] += 1
    for j, col in enumerate(zip(*grid)):
        start, end = -1, -1
        for i, x in enumerate(col):
            if x:
                if start == -1: start = i
                end = i
        if start == -1:
            base += 1
            continue
        if end - start + 1 > k:
            continue
        t, b = max(0, end-k+1), min(n-1, start+k-1)-k+1
        l, r = max(0, j-k+1), min(n-1, j+k-1)-k+1
        diff[l+1][t+1] += 1
        diff[l+1][b+2] -= 1
        diff[r+2][t+1] -= 1
        diff[r+2][b+2] += 1

    ans = 0
    for i in range(1, n-k+3):
        for j in range(1, n-k+3):
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1]
            ans = max(ans, diff[i][j])
    return ans + base

print(solve())