# tle
import sys
from collections import defaultdict
RI = lambda: int(sys.stdin.readline().strip())
RF = lambda: float(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RFF = lambda: map(float, sys.stdin.readline().strip().split())
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
RFLIST = lambda: list(RFF())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
class BIT:
    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def add(self, i, x):
        while i < len(self.tree):
            self.tree[i] += x
            i += i & -i

    def query(self, i):
        ans = 0
        while i:
            ans += self.tree[i]
            i -= i & -i
        return ans

n = RI()
q = []
_set = set()
for i in range(n):
    t, x, v = RII()
    q.append((v, i, t, x)) # 数字， 顺序， 类型， 时间
    _set.add(x) # 对时间离散化

m = {e: i for i, e in enumerate(sorted(_set), 1)}

ans = [-1] * n
cnt = defaultdict(int)
# 按操作数和操作先后排序，同一个数字的操作集中处理
q.sort()

tree = BIT(len(m) + 1)
ans = [-1]*n
for i in range(n):
    v, _, t, x = q[i]
    if i and v != q[i - 1][0]:
        tree = BIT(len(m) + 1)
    if t == 1:
        tree.add(m[x], 1)
    elif t == 2:
        tree.add(m[x], -1)
    else:
        ans[_] = tree.query(m[x])

print('\n'.join(str(x) for x in ans if x != -1))
    