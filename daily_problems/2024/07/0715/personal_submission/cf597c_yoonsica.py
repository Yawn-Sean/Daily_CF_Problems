import sys
from math import inf, comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
# ---------------------------------------分割线---------------------------------------------------------


class BIT:
    def __init__(self, n):
        self.tree = [0] * (n + 1)
    
    def add(self, i, v):
        while i < len(self.tree):
            self.tree[i] += v
            i += i & -i
    
    def query(self, i):
        ans = 0
        while i:
            ans += self.tree[i]
            i &= i - 1
        return ans


n, k = RII()
a = []
f = [0] * (n + 1)  # f[i][j] 以a[j]结尾的长度为i的子序列个数
for i in range(1, n + 1):
    # 左边有多少个比x小的
    x = RI()
    f[x] = 1
    a.append(x)

for i in range(1, k + 1):  # 要求长度为k+1的子序列，第i次循环结束后的f是长度为i + 1的子序列结果
    tree = BIT(n)
    for j in range(1, n + 1):
        tree.add(a[j - 1], f[j])
        f[j] = tree.query(a[j - 1] - 1)

print(sum(f))
