# -*- coding: utf-8 -*-
import bisect
import sys

from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())
Yn = lambda x: print('Yes' if x else 'No')
mod = 1000000007
mod2 = 998244353

tcn = I()
for _tcn_ in range(tcn):
    n, q = MI()
    a = LI()
    a.sort()
    pre_sum = [0] + list(accumulate(a))
    queries = [I() for _ in range(q)]
    st = set()
    st.add(pre_sum[-1])

    stk = [(0, n - 1)]
    while stk:
        i, j = stk.pop()
        if i > j or a[i] == a[j]:
            continue
        if i == j:
            st.add(a[i])
            continue
        mid = (a[i] + a[j]) // 2
        k = bisect.bisect_right(a, mid, lo=i)
        st.add(pre_sum[k] - pre_sum[i])
        st.add(pre_sum[j + 1] - pre_sum[k])
        stk.append((i, k-1))
        stk.append((k, j))

    for v in queries:
        Yn(v in st)
