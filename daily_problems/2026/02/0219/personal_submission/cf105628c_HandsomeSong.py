import math
n, l, r, k = map(int, input().split())
a = list(map(int, input().split()))
min_a = min(a)
if k >= min_a:
    print(-1)
    exit()
a_lcm = 1
limit = r - k + 1
for ai in a:
    g = math.gcd(a_lcm, ai)
    a_lcm = a_lcm // g * ai
    if a_lcm > limit:
        if l <= k <= r:
            print(k)
        else:
            print(-1)
        exit()
if k >= l:
    x = k
else:
    t = (l - k + a_lcm - 1) // a_lcm
    x = a_lcm * t + k
print(x if x <= r else -1)
