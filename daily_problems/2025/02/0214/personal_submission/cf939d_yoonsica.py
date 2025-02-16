import random
import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict
from functools import cmp_to_key
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
https://codeforces.com/problemset/problem/939/D

两个长度=n的字符串，每次操作可以指定两个字母，把一个变成另一个，求让两个字符串相同的最小操作次数

考虑dp
最终肯定每个位置都一样，那么两个字符可能经过一系列转换，如何判断这两个字符目前是否能够通过之前的转换变成相同，
考虑并查集维护可以转换成相同字符的字符集合

'''
n = RI()
s, t = RS(), RS()
uf = UnionFind(26)
ans = 0
path = []
for x, y in zip(s, t):
    a, b = ord(x) - ord('a'), ord(y) - ord('a')
    a, b = uf.find(a), uf.find(b)
    if a != b:
        uf.union(a, b)
        ans += 1
        path.append(' '.join([x, y]))
print(ans)
print('\n'.join(path))