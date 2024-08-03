import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from math import gcd

nq, t2, t1 = lii()
g = gcd(t1, t2)
l = t1 * t2 // g
r = l // t1 + l // t2

def calc():
    k = ii()
    if k % r == 0 or (k+1) % r == 0:
        return 'Both'
    k %= r
    lo, hi = 1, l
    while lo < hi:
        mid = (lo + hi) // 2
        if mid // t1 + mid // t2 < k:
            lo = mid+1
        else:
            hi = mid
    return 'Vanya' if lo % t1 == 0 else 'Vova'

for _ in range(nq):
    print(calc())