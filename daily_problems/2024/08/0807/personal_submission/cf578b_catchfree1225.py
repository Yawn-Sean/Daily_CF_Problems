import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 考慮最大bit誰能提升最多
    # 但還有其他較小的bit，要枚舉討論都有最大bit的數字
    # 可以用前後綴分解討論，統一灌x**k給a[i]
    pre, suf = [0] * n, [0] * n
    for i in range(1, n):
        pre[i] = pre[i - 1] | a[i - 1]
        
    for i in range(n - 2, -1, -1):
        suf[i] = suf[i + 1] | a[i + 1] 
    
    ans = 0
    for i in range(n):
        others = pre[i] | suf[i]
        val = a[i] * x**k
        ans = max(ans, others | val)
    print(ans)
                    
for _ in range(1):
    n, k, x = MII()
    a = list(MII())
    solve()