import sys
input = lambda: sys.stdin.readline().strip()
GMI = lambda: map(lambda x: int(x) - 1, input().split())
MOD = 998244353

def fac(x):
    res = 1
    while x > 1:
        res = res * x % MOD
        x -= 1
    return res

def solve():
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        g[u].append(v)
        g[v].append(u)
        
    # 任選一個點為根，有n種方案
    # 因為不可相交，每個子樹一定是圓中連續一段
    # 父節點與子樹最終要壓成連續的一段
    # 考慮子樹排列: 出度!, 考慮根插入子樹: 出度+1
    # 每個子樹方案數 = 出度! * (出度+1)
    ans = n
    for i in range(n):
        oud = len(g[i]) - 1
        ans = ans * fac(oud) * (oud + 1) % MOD
    print(ans)
               
for _ in range(1):
    n = int(input())
    solve()