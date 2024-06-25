import random
import sys
from functools import reduce

sys.stdin = open('in.txt', 'r')

n: int = int(input())

points: list[list] = [] * n
g: list[list] = [[] for _ in range(n)]

for i in range(n):
    x, y, r = map(int, input().split())
    for j in range(i):
        dx, dy, sr = x - points[j][0], y - points[j][1], r + points[j][2]
        if dx ** 2 + dy ** 2 == sr ** 2:
            g[i].append(j)
            g[j].append(i)
    points.append([x, y, r])

ans = False
col = [0] * n
for i in range(n):
    if not col[i]:
        st = [i]
        col[i] = 1
        s1, s2 = 1, 0
        f = True
        while st:
            u = st.pop()
            for v in g[u]:
                if not col[v]:
                    col[v] = 3 - col[u]
                    if col[v] == 1:
                        s1 += 1
                    else:
                        s2 += 1
                    st.append(v)
                elif col[v] == col[u]:
                    f = False
        if f and s1 != s2:
            ans = True
            break
print('YES' if ans else 'NO')