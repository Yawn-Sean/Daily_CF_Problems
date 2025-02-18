import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from collections import deque

def solve():
    g = [[] for _ in range(n)]
    for i in range(1, n):
        pi, ci = MII()
        pi -= 1
        g[pi].append((i, ci))
    
    q = deque([(0, 0, 0)])
    saved = 0 # 這樣不用統計子樹
    while q: 
        x, preX, preMnX = q.popleft()
        saved += 1
        for y, w in g[x]:
            preY = preX + w
            if preY - preMnX <= a[y]:
                preMnY = min(preMnX, preY)
                q.append((y, preY, preMnY))
    print(n - saved)
               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()