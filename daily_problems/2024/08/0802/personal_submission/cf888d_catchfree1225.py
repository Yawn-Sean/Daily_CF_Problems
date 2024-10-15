import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import comb

def solve():
    dearrange = [1] * (k + 1)
    for i in range(1, k + 1):
        dearrange[i] = i * dearrange[i - 1] + (-1)**i
    
    ans = 1
    for x in range(n - k, n - 1):
        ans += comb(n, x) * dearrange[n - x]
    print(ans)
    
    
for _ in range(1):
    n, k = MII()
    solve()