#https://codeforces.com/problemset/problem/799/C
from collections import  *
import sys
import math
import bisect
input = lambda :sys.stdin.readline().rstrip()
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
n,c,d = RII()
coins, diomands = [], []
for _ in range(n):
    b,p,t = input().split()
    if t == 'C':
        coins.append((int(p),int(b)))
    else:
        diomands.append((int(p),int(b)))
c_mx,d_mx = 0,0
ans = 0

coins.sort()
co,co_values = [],[]
for i in range(len(coins)):
    co.append(coins[i][0])
    co_values.append(coins[i][1])
j = bisect.bisect_left(co,c+1) - 1  #二分找到<=c的第一个下标
if j >= 0:
    opt = coins[:j + 1]  # 存储价格和价值
    opt1 = co_values[:j + 1]  # 只存储价值
    opt2 = co[:j + 1]  # 只存储价格
    #只选一个C的话肯定选最大的
    c_mx = max(opt1)
    #print(c_mx)
    mx_c = opt1  # 前缀最大值
    '''print(opt)
    print(mx_c)'''
    for i in range(1, j + 1):
        mx_c[i] = max(mx_c[i - 1], mx_c[i])
    res = 0
    #找两个C中的
    if len(opt) >= 2:
        for i in range(1, j + 1):
            e, v = opt[i][0], opt[i][1]
            if e + opt2[0] > c:
                break
            j = min(i - 1, bisect.bisect_left(opt2, c - e + 1) - 1)  # 规定j<i
            res = max(res, mx_c[j] + v)
        ans = max(ans, res)
#和上面同样的处理逻辑
diomands.sort()
co,co_values = [],[]
for i in range(len(diomands)):
    co.append(diomands[i][0])
    co_values.append(diomands[i][1])
j = bisect.bisect_left(co,d+1) - 1  #二分找到<=c的第一个下标
if j >= 0:
    opt = diomands[:j + 1]  # 存储价格和价值
    opt1 = co_values[:j + 1]  # 只存储价值
    opt2 = co[:j + 1]  # 只存储价格
    d_mx = max(opt1)
    mx_d = opt1  # 前缀最大值
    for i in range(1, j + 1):
        mx_d[i] = max(mx_d[i - 1], mx_d[i])
    res = 0

    if len(opt) >= 2:
        for i in range(1, j + 1):
            e, v = opt[i][0], opt[i][1]
            if e + opt2[0] > d:
                break
            j = min(i - 1, bisect.bisect_left(opt2, d - e + 1) - 1)  # 规定j<i
            res = max(res, mx_d[j] + v)
        ans = max(ans, res)
if c_mx > 0 and d_mx > 0:
    ans = max(ans,c_mx+d_mx)
print(ans)
