import sys
from math import inf, log2

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1510/D

n个数，选出若干个数，乘积以d结尾且乘积最大

把乘积通过log转换成加法
'''
n, d = RII()
a = RILIST()
f = [[-inf]*10 for _ in range(n)] # 前i个数选出的结尾为j的log最大和
f[0][a[0] % 10] = log2(a[0])
pre = [[-1]*10 for _ in range(n)]
pre[0][a[0] % 10] = -1 # -1代表不用往前找了

for i, x in enumerate(a[1:], 1):
    f[i][x % 10] = log2(x)
    for j in range(10):
        if f[i - 1][j] > f[i][j]:
            f[i][j] = f[i - 1][j] # 不选i
            pre[i][j] = j
    for j in range(10):
        if log2(x) + f[i - 1][j] > f[i][(j * x) % 10]:
            f[i][(j * x) % 10] = log2(x) + f[i - 1][j]
            pre[i][(j * x) % 10] = j

if f[-1][d] == -inf:
    print(-1)
    exit()
ans = []
i, j = n - 1, d
for i in range(n - 1, -1, -1):
    if i and f[i - 1][j] == f[i][j]: # 不选a[i]
        continue
    else:
        ans.append(a[i])
        j = pre[i][j]
        if j == -1:
            break
print(len(ans))
print(' '.join(map(str, ans[::-1])))