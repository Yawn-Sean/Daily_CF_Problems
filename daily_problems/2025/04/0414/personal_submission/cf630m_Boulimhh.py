"""
菜鸡大模拟无需多言，wa了好多次，纯属情况没考虑清楚
"""
# python代码
import sys
input = lambda:sys.stdin.readline().strip()
fmin = lambda x, y: x if x < y else y

n = int(input())
flag = -1 if n >= 0 else 1
n %= 360
if flag == 1:
    n = 360 - n
else: n = -n

cnt = 0
res = fmin(abs(n), 360 - abs(n))
for i in range(1, 4):
    n += 90
    t = fmin(abs(n), abs(360 - abs(n)))
    if t < res:
        res = t
        cnt = i
print(cnt)
