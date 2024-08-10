import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
MOD = int(1e9 + 7)

def solve():
    # x = b*(rk) + r
    # ans = 0
    # for r in range(b): 
    #     for k in range(1, a + 1):
    #         ans += b * (r * k) + r
    
    ans = b * (b - 1) // 2 * (a * (a + 1) * b // 2 + a) % MOD
    print(ans)
               
for _ in range(1):
    a, b = MII()
    solve()