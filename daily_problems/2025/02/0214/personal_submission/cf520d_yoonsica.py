import random
import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict
from functools import cmp_to_key
from heapq import heappush, heappop
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
class UnionFind:
    def __init__(self, n):
        self.fa = list(range(n))

    def find(self, x):
        st = []
        while self.fa[x] != x:
            st.append(x)
            x = self.fa[x]
        while st:
            self.fa[st.pop()] = x
        return x

    def union(self, x, y):
        a, b = self.find(x), self.find(y)
        if a != b:
            self.fa[a] = b

    def is_same(self, x, y):
        return self.find(x) == self.find(y)
'''
https://codeforces.com/problemset/problem/520/D
模拟
'''
n = RI()
m = defaultdict(int)
a = []
vis = set()
for i in range(1, n + 1):
    x, y = RII()
    a.append((x, y))
    m[x, y] = i

h_max, h_min = [], []
def check(x, y):
    # 检查(x, y)能不能拿走
    if m[x, y + 1] and m[x - 1, y] == 0 and m[x + 1, y] == 0:
        return False
    if m[x - 1, y + 1] and m[x - 1, y] == 0 and m[x - 2, y] == 0:
        return False
    if m[x + 1, y + 1] and m[x + 1, y] == 0 and m[x + 2, y] == 0:
        return False
    return True


def update(x, y):
    if m[x, y - 1] and check(x, y - 1):
        # 下方可以拿走
        heappush(h_max, -m[x, y - 1])
        heappush(h_min, m[x, y - 1])
    if m[x - 1, y - 1] and check(x - 1, y - 1):
        # 下方可以拿走
        heappush(h_max, -m[x - 1, y - 1])
        heappush(h_min, m[x - 1, y - 1])
    if m[x + 1, y - 1] and check(x + 1, y - 1):
        # 下方可以拿走
        heappush(h_max, -m[x + 1, y - 1])
        heappush(h_min, m[x + 1, y - 1])
        

for i in range(1, n + 1):
    x, y = a[i - 1]
    if check(x, y):
        heappush(h_max, -i)
        heappush(h_min, i)

ans = []
i = 1
while i <= n:
    if i & 1:
        ans.append(-heappop(h_max))
    else:
        ans.append(heappop(h_min))
    x, y = a[ans[-1] - 1]
    if ans[-1] in vis or not check(x, y):
        ans.pop()
        continue
    else:
        vis.add(ans[-1])
        m[x, y] = 0
        update(x, y)
    i += 1
    
mod = 10**9 + 9
s, d = 0, 1
print(ans)
for i in range(n):
    s = (s + (ans[n - 1 - i] - 1) * d) % mod
    d = d * n % mod
print(s)