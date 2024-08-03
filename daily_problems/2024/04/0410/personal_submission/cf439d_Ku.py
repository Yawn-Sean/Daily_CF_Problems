import bisect
import sys
import math
from itertools import accumulate
sys.setrecursionlimit(30000)
input = lambda:sys.stdin.readline().rstrip()
n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
a.sort()
b.sort()
ac_a = list(accumulate(a,initial=0))
ac_b = list(accumulate(b,initial=0))

ans = math.inf
for i,x in enumerate(a):
    #a种找小于x的，增加到x
    a_incr = x * (i) - ac_a[i]
    #b中大于x的，下降到x
    j = bisect.bisect_right(b,x)
    b_drop = ac_b[-1] - ac_b[j] - (len(b) - j) * x
    ans = min(ans,a_incr + b_drop)

for i,x in enumerate(b):
    #b中找大于x的，下降到x
    b_drop = ac_b[-1] - ac_b[i+1] - (len(b) - i - 1) * x
    #a中小于x的，增加到x
    j = bisect.bisect_left(a,x)
    a_incr = x * j - ac_a[j]
    ans = min(ans,a_incr + b_drop)
print(ans)
