import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from math import isqrt

def solve():
    # key: 遇到floor計算不等式，可以列出極值
    # 注意到左式: 0<=floor(n//(x+1))<=n
    # 會對根號n對稱(只需枚舉到根號n)
    
    if k > n + m - 2:
        print(-1)
        return 
    
    def calc(h):
        # 多一個n//i有時候會變成0(避免特判)
        # 配對失敗都會回傳0
        cnty = max(k + 2 - n // h, 1)
        return h * (m // cnty)
    
    ans = 0 # 枚舉邊長，最小為1，最大到根號n(後面重複)
    for h in range(1, isqrt(n) + 1):
        ans = max(ans, calc(h), calc(n // h))
    print(ans)

               
for _ in range(1):
    n, m, k = MII()
    solve()