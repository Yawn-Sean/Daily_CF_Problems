import sys
import math

input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
g = [[] for _ in range(n)]
mark = [-1] * n
for _ in range(m):
    u, v = map(int, input().split())
    g[u-1].append(v-1)
    g[v-1].append(u-1)

s = []
flag = True
for u in range(n):
    if not flag:
        break
    if mark[u] == -1:
        if len(g[u]) == 0:
            continue
        s.append(u)
        mark[u] = 0
        while s:
            if not flag:
                break
            u = s.pop()
            for v in g[u]:
                if mark[v] == mark[u]:
                    print(-1)
                    flag = False
                    break
                elif mark[v] == -1:
                    mark[v] = mark[u] ^ 1
                    s.append(v)

# def dfs(u: int, clr: int=1) -> bool:
#     if len(g[u]) == 0:
#         return True
#     mark[u] = clr
#     for v in g[u]:
#         if mark[v] == clr:
#             return False
#         if mark[v] == 0:
#             flag = dfs(v, 3 - clr)
#             if not flag:
#                 return False
#     return True
#
# f = True
# for u in range(n):
#     if mark[u] == 0:
#         f = dfs(u, 1)
#         if not f:
#             print(-1)
#             break

if flag:
    ans1 = [x+1 for x in range(n) if mark[x] == 1]
    ans2 = [x+1 for x in range(n) if mark[x] == 0]
    print(len(ans1))
    for x in ans1:
        print(x, end=' ')
    print()
    print(len(ans2))
    for x in ans2:
        print(x, end=' ')
