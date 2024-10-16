import sys
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
RF = lambda: float(sys.stdin.readline().strip())
RFF = lambda: map(float, sys.stdin.readline().strip().split())
inf = 10 ** 19

n = RI()
a = sorted(RILIST())
N = 5000
# 三轮总方案数 = comb(n, 2) ^ 3
total = pow(comb(n,2), 3)
cnt = [0]*N
for i, x in enumerate(a):
    for j, y in enumerate(a[:i]):
        cnt[x - y] += 1

cnt2 = [0]*N # 前两轮的分差和，由于第三次最高5000，所以这里大于等于5000的不用管
for i, x in enumerate(cnt):
    for j, y in enumerate(cnt):
        if i + j < 5000:
            cnt2[i + j] += x*y

s = [0]*N
for i in range(1, 5000):
    s[i] = s[i - 1] + cnt2[i]

ans = 0
# 第三轮B的分要大于前两轮分差
for x in range(1, 5000):
    ans += cnt[x] * s[x - 1]

print(ans / total)