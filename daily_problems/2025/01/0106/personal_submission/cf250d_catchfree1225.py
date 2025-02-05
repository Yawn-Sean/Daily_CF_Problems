import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import sqrt, inf

# WA: 0, 用時: 30min, 日期: 20250106
def calc(i, j):
    def dist(x, y):
        return sqrt((x[0] - y[0])**2 + (x[1] - y[1])**2)
    oa = dist((0, 0), pa[i])
    ab = dist(pa[i], pb[j])
    return oa + ab + l[j]

def bisect(j):
    l, r = 0, n - 1
    while l < r:
        mid = (l + r) // 2
        if calc(mid, j) > calc(mid + 1, j):
            l = mid + 1
        else:
            r = mid
    return l

def solve():
    ans, ai, bj = inf, -1, -1
    for j in range(m):
        i = bisect(j)
        new_val = calc(i, j)
        if new_val < ans:
            ans = new_val
            ai, bj = i, j

    print(ai + 1, bj + 1)                
               
for _ in range(1):
    n, m, a, b = MII()
    pa = [(a, x) for x in MII()]
    pb = [(b, x) for x in MII()] 
    l = list(MII())
    solve()