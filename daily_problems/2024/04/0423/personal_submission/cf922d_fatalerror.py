"""
字符串内部的 'sh' 子序列数已经确定，影响结果的只有字符串之间新形成的 'sh' 子序列数。
设两字符串包含的 's' 和 'h' 个数分别为 (s1, h1) 和 (s2, h2) ，其先后顺序可以由 s1*h2 和 s2*h1 的大小关系决定，而涉及比较关系的排序可以使用 functools.cmp_to_key 。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())

from functools import cmp_to_key

def cmp(p0, p1):
    s0, h0 = p0
    s1, h1 = p1
    if s0 * h1 > s1 * h0:
        return -1
    elif s0 * h1 < s1 * h0:
        return 1
    return 0

pairs = []
ans = 0
for _ in range(ii()):
    t = input()
    s, h = 0, 0
    for ch in t:
        if ch == 's':
            s += 1
        else:
            ans += s
            h += 1
    pairs.append((s, h))
pairs.sort(key=cmp_to_key(cmp))
tots = 0
for s, h in pairs:
    ans += tots * h
    tots += s

print(ans)