def check(cur):
    global x, k
    if cur % x == 0:
        p = -1
    else:
        p = 0
    most = cur - cur % x + (k + 1 + p) * x
    lest = cur - cur % x + (k + p) * x
    return most, lest
from bisect import *
n, x, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

ans = 0
for i in a:
    r, l = check(i)
    l = max(l, i)

    ans += bisect_left(a, r) - bisect_left(a, l)
    
print(ans)
    
