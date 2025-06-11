import sys
from math import gcd
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

l, r, x, y = map(int, input().split())
if y % x:
    exit(print(0))

if x == y:
    exit(print(1 if l <= x <= r else 0))

z = y // x
ans = 0
for i in range(1, 100000):
    if i * i >= z:
        break
    if z % i == 0 and gcd(i, z // i) == 1 and l <= i * x <= r and l <= z // i * x <= r:
        ans += 2
print(ans)
