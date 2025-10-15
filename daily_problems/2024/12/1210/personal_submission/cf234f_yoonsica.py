import sys
from math import inf

standard_input = False
if standard_input:
    RI = lambda: int(sys.stdin.readline().strip())
    RF = lambda: float(sys.stdin.readline().strip())
    RS = lambda: sys.stdin.readline().strip()
    RFF = lambda: map(float, sys.stdin.readline().strip().split())
    RII = lambda: map(int, sys.stdin.readline().strip().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())

else:
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()
    RI = lambda: int(input())
    RF = lambda: float(input())
    RS = lambda: input()
    RFF = lambda: map(float, input())
    RII = lambda: map(int, input().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())
    
    
    def print(x):
        fout.write(str(x))

mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

n = RI()
a, b = RII()
h = [0] + RILIST()

# 朴素想法 case11 tle
# 前i个，涂了红色高度和j，绿色k, 当前涂色为x的最小不美观
# f = [[[[inf]*2 for _ in range(b + 1)] for _ in range(a + 1)] for _ in range(n + 1)]
# for j in range(a + 1):
#     for k in range(b + 1):
#         f[0][j][k][0] = f[0][j][k][1] = 0
#
# for i, x in enumerate(h[1:], 1):
#     for j in range(a + 1):
#         for k in range(b + 1):
#             if j >= x:
#                 f[i][j][k][0] = mn(f[i - 1][j - x][k][0], f[i - 1][j - x][k][1] + mn(x, h[i - 1]))
#             if k >= x:
#                 f[i][j][k][1] = mn(f[i - 1][j][k - x][1], f[i - 1][j][k - x][0] + mn(x, h[i - 1]))
# ans = min(f[-1][-1][-1])
# print(ans if ans < inf else -1)

# 考虑优化，j + k = sum(h[:i]),可以去掉一维
# 前i个，涂了红色高度和j, 当前涂色为x的最小不美观
# 滚动数组优化，不滚动tle
# a = mn(sum(h), a)
f = [[inf] * 2 for _ in range(a + 1)]
f[0][0] = f[0][1] = 0
g = [[inf] * 2 for _ in range(a + 1)]
s = 0
ans = inf
for i, x in enumerate(h[1:], 1):
    s += x
    for j in range(mx(0, s - b), mn(a, s) + 1):
        cost = mn(x, h[i - 1])
        if j >= x:
            g[j][0] = mn(f[j - x][0], f[j - x][1] + cost)
        g[j][1] = mn(f[j][1], f[j][0] + cost)
        if i == n:
            ans = mn(ans, mn(g[j][0], g[j][1]))
    for j in range(a + 1):
        f[j][0], f[j][1] = g[j][0], g[j][1]
        g[j][0], g[j][1] = inf, inf
print(ans if ans < inf else -1)
