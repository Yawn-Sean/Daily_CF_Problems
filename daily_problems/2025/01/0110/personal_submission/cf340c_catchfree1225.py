import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import gcd

# WA:1, time:2hr, dt:20250110
def solve1():
    m = n - 1
    d = [0] * (m + 2)
    for i in range(m):
        l, r = i, m - 1
        s, e, k = m - i, 1, -1
        d[l] += s
        d[l + 1] += k - s
        d[r + 1] -= k + e
        d[r + 2] += e
    
    for i in range(1, n):
        d[i] += d[i - 1]
    for i in range(1, n):
        d[i] += d[i - 1]
    
    ans = sum(a)
    for i in range(m):
        ans += d[i] * (a[i + 1] - a[i]) * 2
    
    gd = gcd(ans, n)
    p, q = ans // gd, n // gd
    print(p, q)

def solve():
    ans = sum(a)
    for i in range(n): # 考慮期望值分解, i,j對稱
        left = i
        right = n - i - 1
        ans += 2 * (left - right) * a[i]
        
    gd = gcd(ans, n)
    p, q = ans // gd, n // gd
    print(p, q)
    
for _ in range(1):
    n = int(input())
    a = sorted(MII())
    solve()