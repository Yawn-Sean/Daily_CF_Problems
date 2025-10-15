'''
https://codeforces.com/problemset/submission/327/299068988
327D
2024/12/30 Y2
1900
DFS
'''
# 矩阵图DFS搜索
from itertools import pairwise
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    grid = [[-c.count('#') for c in input()] for _ in range(n)]
    return n, m, grid

def solve(n: int, m: int, grid: list[list[int]]):
    ans = []

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                # 非递归实现
                stk = []
                stk.append((i, j, 0, 1))
                while stk:
                    ci, cj, hasParent, isPreOrder = stk.pop()
                    if not isPreOrder:
                        if hasParent:
                            ans.append(f"D {ci + 1} {cj + 1}")
                            ans.append(f"R {ci + 1} {cj + 1}")
                        continue
                    grid[ci][cj] = 2 # 1-middle node, 2-leaf
                    for d1, d2 in pairwise([0, 1, 0, -1, 0]):
                        ni, nj = ci + d1, cj + d2
                        if 0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 0:
                            if grid[ci][cj] == 2:
                                grid[ci][cj] = 1
                                ans.append(f"B {ci + 1} {cj + 1}")
                                stk.append((ci, cj, hasParent, 0))
                            grid[ni][nj] = 3 # WA: 忘记染色，导致重复入栈
                            stk.append((ni, nj, 1, 1))
                    if grid[ci][cj] == 2:
                        if hasParent:
                            ans.append(f"R {ci + 1} {cj + 1}")
                        else:
                            ans.append(f"B {ci + 1} {cj + 1}")
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    print('\n'.join(ans))
