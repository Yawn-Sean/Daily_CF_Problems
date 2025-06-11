import sys
from math import gcd

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
# ---------------------------------------分割线---------------------------------------------------------
l, r, x, y = RII()
# lcm(a,b) = a*b / gcd(a,b)
# y = a*b / x   x*y = a*b

ans = 0


def check(a):
    if l <= a <= r:
        b = x * y // a  # b = x*y//a
        if l <= b <= r and gcd(a, b) == x:
            return True
    return False


i = 1
while i * i <= y:
    # 枚举y的因子看是否能作为a
    if y % i == 0:
        if check(i):
            ans += 1
        if y // i != i and check(y // i):
            ans += 1
    i += 1
print(ans)
