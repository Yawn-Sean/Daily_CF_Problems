import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import inf

# Key: 想清楚每一題上限與下限!
# WA:3, time:1.5hr, dt:20250109 (failed)
def solve():
    a = [inf] * n
    adds = [0] * n
    for op in ops:
        if op[0] == 1:
            li, ri, di = op[1:]
            for i in range(li - 1, ri):
                adds[i] += di
        else:
            li, ri, mi = op[1:]
            for i in range(li - 1, ri):
                if a[i] + adds[i] > mi:
                    a[i] = mi - adds[i]

    adds = [0] * n
    for op in ops:
        if op[0] == 1:
            li, ri, di = op[1:]
            for i in range(li - 1, ri):
                adds[i] += di
        else:
            li, ri, mi = op[1:]
            if all(a[i] + adds[i] < mi for i in range(li - 1, ri)):
                print('NO')
                return
    
    print('YES')
    print(*[x if x < inf else int(1e9) for x in a])
    
               
for _ in range(1):
    n, m = MII()
    ops = [list(MII()) for _ in range(m)]
    solve()