import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

a, b, nq = mii()
getsum = lambda l, r: (a*2 + (l+r-2) * b) * (r-l+1) // 2

def solve():
    left, t, m = mii()
    base = a + (left-1) * b
    if base > t:
        return -1
    l, r = left, left + (t - base) // b
    while l < r:
        mid = (l + r + 1) // 2
        if getsum(left, mid) <= m * t:
            l = mid
        else:
            r = mid - 1
    return l

for _ in range(nq):
    print(solve())