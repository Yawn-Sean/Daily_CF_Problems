import sys
from math import gcd
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n = RI()
ans = cnt = 0
a = RILIST()
if gcd(*a) > 1:
    print('YES')
    print(0)
    exit()
for x in a:
    if x & 1:
        cnt += 1
    else:
        ans += cnt // 2
        if cnt & 1:
            ans += 2
        cnt = 0
ans += cnt // 2
if cnt & 1:
    ans += 2
print('YES')
print(ans)
