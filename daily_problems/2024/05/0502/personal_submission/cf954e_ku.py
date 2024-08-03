#https://codeforces.com/problemset/problem/954/E
from collections import  *
import sys
input = lambda :sys.stdin.readline().rstrip()
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
n, T = RII()
a = RILIST()
t = RILIST()
t_so = sorted(range(n),key = lambda x:t[x])
#假设全打开
s = sum(a)
ans = s
cnt = 0
c = 0
for i in range(n):
    cnt += a[i] * t[i]
temp = cnt / s
if temp == T:
    print(ans)
    exit()
elif temp > T:
    #优先关掉温度大于T的
    for i in range(n-1,-1,-1):
        opt = t_so[i]
        if t[opt] <= T or s == a[opt]:
            break
        if (cnt - a[opt] * t[opt]) / (s - a[opt]) > T:
            #关掉最大的依然不满足，那就继续关次大的
            cnt -= a[opt] * t[opt]
            s -= a[opt]
            ans -= a[opt]
        else:
            #关掉某一个后会满足条件，那么计算这个要关多少
            ans -= (cnt - T * s) / (t[opt] - T)
            c = 1
            break

else:
    # 优先关掉温度小于T的
    for i in range(n):
        opt = t_so[i]
        if t[opt] >= T or s == a[opt]:
            break
        if (cnt - a[opt] * t[opt]) / (s - a[opt]) < T:
            cnt -= a[opt] * t[opt]
            s -= a[opt]
            ans -= a[opt]
        else:
            ans -= (cnt - T * s) / (t[opt] - T)
            c = 1
            break
if c == 1:
    print(ans)
else:
    print(0)
