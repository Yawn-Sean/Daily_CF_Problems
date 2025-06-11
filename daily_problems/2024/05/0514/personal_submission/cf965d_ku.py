import sys
import math
import bisect
input = lambda :sys.stdin.readline().rstrip()
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
w, l = RII()
li = RILIST()

res = sum(li[0:l])
cnt = res
for i in range(1,w - l):
    res -= li[i-1]
    res += li[l+i-1]
    cnt = min(cnt,res)
print(cnt)
