from math import gcd

l1, r1, t1 = map(int, input().split())
l2, r2, t2 = map(int, input().split())

step = gcd(t1, t2)

dis = ((l2 - l1) % step + step) % step

overlap1 = min(l2 - dis + r1 - l1 - l2 + 1, r2 - l2 + 1)
ans = max(0, overlap1)

dis -= step
overlap2 = min(r2 - (l2 - dis) + 1, r1 - l1 + 1)
ans = max(ans, max(0, overlap2))

print(ans)
