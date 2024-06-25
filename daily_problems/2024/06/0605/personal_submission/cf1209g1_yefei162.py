# -*- coding: utf-8 -*-
import sys
from collections import defaultdict, Counter

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())

tcn = 1
for _tcn_ in range(tcn):
    n, _ = MI()
    A = LI()
    groups = defaultdict(list)
    for i, x in enumerate(A):
        groups[x].append(i)

    sections = []
    for _, group in groups.items():
        section = (group[0], group[-1])
        sections.append(section)

    sections.sort(key=lambda x: (x[0], -x[1]))

    merges = []
    left, right = sections[0]
    for i in range(1, len(sections)):
        start, end = sections[i]
        if start > right:
            merges.append((left, right))
            left, right = start, end
        else:
            right = max(right, end)
    merges.append((left, right))
    ans = 0
    for left, right in merges:
        cnt = Counter(A[left:right+1])
        ans += right - left + 1 - cnt.most_common(1)[0][1]
    print(ans)
