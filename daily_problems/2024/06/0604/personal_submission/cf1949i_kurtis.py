import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 只要有一个联通块可以变小就行
# 只有n个点，n-1个交点的块可以
# 错了，还可能有其他情况，得抽象成二染色问题
n = II()
g = [[] for _ in range(n)]
disk = [LMII() for _ in range(n)]

# 建图
for i in range(n):
    x1, y1, r1 = disk[i]
    for j in range(i):
        x2, y2, r2 = disk[j]
        if (x1 - x2) ** 2 + (y1 - y2) ** 2 == (r1 + r2) ** 2:
            g[i].append(j)
            g[j].append(i)

# 开始染色
flag = False
col = [-1] * n
for i in range(n):
    if col[i] == -1: # 还没染色，默认是0
       col[i] = 0
       f, c0, c1 = True, 1, 0
       # 用栈模拟dfs
       stk = [i]
       while stk:
           u = stk.pop()
           for v in g[u]:
               if col[v] == -1:
                   col[v] = col[u] ^ 1 # 取另一种颜色
                   if col[v]:
                       c1 += 1
                   else:
                       c0 += 1
                   stk.append(v)
               elif col[v] ^ col[u] != 1: # 冲突了
                   f = False
       if f and c0 != c1:
           flag = True
           break # 找到一组就行
       
print('YES' if flag else 'NO')