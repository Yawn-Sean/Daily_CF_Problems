# # 最多每个点遍历一次(有一个点遍历两次)，时间复杂度 O(nm)
# n, m = map(int, input().split())
# maze = [input() for _ in range(n)]

# def f(x, y):
#     return x * m + y

# sx = sy = 0
# for i in range(n):
#     for j in range(m):
#         if maze[i][j] == 'S':
#             sx, sy = i, j
#             break

# vis = [None] * (n * m)

# stk = [(sx, sy)]
# vis[f(sx, sy)] = (sx, sy)

# dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

# while stk:
#     x, y = stk.pop()
#     for dx, dy in dirs:
#         nx = x + dx
#         ny = y + dy
#         px = nx % n
#         py = ny % m
#         if maze[px][py] != '#':
#             if vis[f(px, py)] is not None:
#                 if vis[f(px, py)] != (nx, ny):
#                     print('Yes')
#                     exit()
#             else:
#                 vis[f(px, py)] = (nx, ny)
#                 stk.append((nx, ny))

# print('No')


import io, os, sys
input = lambda: sys.stdin.readline().strip()

import math
inf = math.inf

def I():
    return input()

def II():
    return int(input())

def MII():
    return map(int, input().split())

def LI():
    return list(input().split())

def LII():
    return list(map(int, input().split()))

def LFI():
    return list(map(float, input().split()))

def GMI():
    return map(lambda x: int(x) - 1, input().split())

def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))



INF = float('inf')
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def f(x, y):
    return x * m + y

def bfs(sx, sy):
    stack = [(sx, sy)]
    vis[f(sx, sy)] = (sx + 1) * 2000 + sy + 1
    while stack:
        x, y = stack.pop()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            px, py = nx % n, ny % m
            if maze[px][py] != '#':
                if vis[f(px, py)] != 0:
                    if vis[f(px, py)] != (nx + 1) * 2000 + ny + 1:
                        return True
                else:
                    vis[f(px, py)] = (nx + 1) * 2000 + ny + 1
                    stack.append((nx, ny))
    return False

n, m = MII()
maze = [I() for _ in range(n)]

sx = sy = 0
for i in range(n):
    for j in range(m):
        if maze[i][j] == 'S':
            sx, sy = i, j
            break

vis = [0] * (n * m)

if bfs(sx, sy):
    print('Yes')
else:
    print('No')

