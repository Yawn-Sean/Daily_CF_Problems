import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())

def solve():
    # Key: 改維護可轉移
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = GMI()
        g[u].append(v)
    
    bad = {a[-1]}
    for x in reversed(a[:-1]):
        move = len(set(g[x]) & bad)
        if move < len(bad):
            bad.add(x)
        
    print(n - len(bad))
               
for _ in range(1):
    n, m = MII()
    a = list(GMI())
    solve()