import sys
input = lambda: sys.stdin.readline().rstrip()
from math import inf

def solve():
    n, ca, cb = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    m = 2 * n
    cost = [0] * (m + 1)
    for i, v in enumerate(b):
        cost[v] = cb * i
    
    sf = [inf] * (m + 2)
    for v in range(m, 0, -1):
        if v % 2 == 0:
            sf[v] = cost[v] if cost[v] < sf[v + 1] else sf[v + 1]
        else:
            sf[v] = sf[v + 1]
    
    ans = inf
    for i, v in enumerate(a):
        cur = ca * i
        if v + 1 <= m:
            cur += sf[v + 1]
            if cur < ans:
                ans = cur
    
    print(ans)

T = int(input())
for _ in range(T):
    solve()
