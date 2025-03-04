import sys
from bisect import bisect_right, bisect_left
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/803/D
'''
k = RI()
s = RS()
n = len(s)
# 记录一下空格和-的下标，可截取的位置
pos = []
for i, x in enumerate(s):
    if x in '- ':
        pos.append(i)
if not pos or pos[-1] != 'n - 1':
    pos.append(n - 1)

'''
划分为k行，最长的一行长度最短为mid
'''
def check(mid):
    if mid * k < n:
        return False
    i, cnt = -1, 0 # i上一句最后一个字符位置
    while i < n - 1:
        j = bisect_right(pos, i + mid) - 1 # 下一个可截断位置
        if j < 0:
            return False
        cnt += 1
        i = pos[j]
        if cnt > k:
            return False
    return True

l, r = 0, n + 1
while l + 1 < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid

print(r)