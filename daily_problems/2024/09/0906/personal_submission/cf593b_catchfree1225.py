import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # Key: 可用'邊界'找交點(IVT介值定理)
    # If f is cont on [a, b] and f[a] * f[b] < 0,
    # then f has root in [a, b]. 
    # (此題先算出一邊的值排序，再看另一側有沒逆序即可)
    
    a = [None] * n
    for i in range(n):
        ki, bi = MII()
        a[i] = ki * x1 + bi, ki * x2 + bi
    a.sort()
    
    for i in range(n - 1):
        if a[i][1] > a[i + 1][1]: # 逆序
            print('YES')
            return
    print('NO')
                
                
for _ in range(1):
    n = int(input())
    x1, x2 = MII()
    solve()