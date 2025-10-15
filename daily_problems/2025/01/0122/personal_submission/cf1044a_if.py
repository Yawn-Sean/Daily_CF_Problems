if 1:
    from collections import Counter
    def I():
        return input().strip()
    def LI():
        return list(input())
    import sys  
    #sys.set_int_max_str_digits(6000)
    from heapq import *
    input = sys.stdin.readline
    from bisect import bisect_left, bisect_right
    import math
    def II():
        return int(input())
    def LII():
        return list(map(int, input().split()))

    def MII():
        return map(int, input().split())
    inf = int(float(1e10))
    import random #random.shuffle()

n, m = MII()
x = []
cnt = 0
for _ in range(n):
    xx = II()
    x.append(xx)
x.sort()
y = []
for _ in range(m):
    x1, x2, yy = MII()
    if x1 == 1 and x2 == 1e9:
        cnt += 1
        continue
    if x1 != 1:
        continue
    y.append(x2)
y.sort()
x, y = y, x
while x and y and x[0] < y[0]:
    x.pop(0)
ans = min(len(x), len(y))
y.append(1e10)
for i in range(len(y)):
    tar = y[i]
    need = len(x) - bisect_left(x, tar)
    ans = min(ans, i + need)
print(ans + cnt)
