# -*- coding: utf-8 -*-
import sys
from typing import Sequence, List


def knuth_morris_pratt(text: Sequence, pattern: Sequence) -> List[int]:
    """
    Given two strings text and pattern, return the list of start indexes in text that matches with the pattern
    using knuth_morris_pratt algorithm.

    Args:
        text: Text to search
        pattern: Pattern to search in the text
    Returns:
        List of indices of patterns found

    Example:
        # >>> knuth_morris_pratt('hello there hero!', 'he')
        [0, 7, 12]

    If idx is in the list, text[idx : idx + M] matches with pattern.
    Time complexity of the algorithm is O(N+M), with N and M the length of text and pattern, respectively.
    """
    n = len(text)
    m = len(pattern)
    pi = [0 for i in range(m)]
    i = 0
    j = 0
    # making pi table
    for i in range(1, m):
        while j and pattern[i] != pattern[j]:
            j = pi[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j
    # finding pattern
    j = 0
    ret = []
    for i in range(n):
        while j and text[i] != pattern[j]:
            j = pi[j - 1]
        if text[i] == pattern[j]:
            j += 1
            if j == m:
                ret.append(i - m + 1)
                j = pi[j - 1]
    return ret


input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n, m = MI()
    t = list(input())
    idxs = LGMI()

    s = ['0'] * n
    fa = [_ for _ in range(n + 1)]


    def find(x):
        r = x
        while r != fa[r]:
            r = fa[r]

        k = x
        while k != r:
            fa[k], k = r, fa[k]
        return fa[x]


    def union(x, y):
        fx = find(x)
        fy = find(y)
        if fx > fy:
            fa[fy] = fx
        else:
            fa[fx] = fy


    for i in idxs:
        start = i
        cur = i
        while True:
            cur = find(cur)
            if cur >= start + len(t):
                break

            s[cur] = t[cur - start]
            union(cur, cur + 1)
            cur = find(cur)
    # print(s)

    rets = knuth_morris_pratt(s, t)
    # print(rets)
    # print(idxs)
    i = 0
    for j in range(len(rets)):
        if i < len(idxs) and idxs[i] == rets[j]:
            i += 1

    if i < len(idxs):
        print(0)
    else:
        ans = pow(26, s.count('0'), mod)
        print(ans)
