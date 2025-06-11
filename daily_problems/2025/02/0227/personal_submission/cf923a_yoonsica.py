import sys
from math import inf, sqrt

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/923/A
x2 - p2 < x1 <= x2
x1 - p1 < x0 <= x1
x0最小，需要x1最小，p1最大
x1最小，需要x2最小，p2最大
'''
n = 10**6 + 1
# 预处理x的最大质因子
is_prime = [1] * n
for i in range(2, n):
    if is_prime[i] == 1:
        for j in range(i + i, n, i):
            is_prime[j] = i


x2 = RI()
p2 = is_prime[x2]
ans = inf
for x1 in range(x2 - p2 + 1, x2 + 1):
    p1 = is_prime[x1]
    if x1 - p1 + 1 < 3:
        continue
    ans = mn(ans, x1 - p1 + 1)
print(ans)