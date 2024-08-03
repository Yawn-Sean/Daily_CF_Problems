# 快读板子
import sys
from functools import cmp_to_key

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()

a = []
for _ in range(RI()):
    a.append(RS())

h, s = [x.count('h') for x in a], [x.count('s') for x in a]


def cmp(i, j):
    return s[i] * h[j] - s[j] * h[i]


ans = cnt_s = 0
for i in sorted(range(len(a)), key=cmp_to_key(cmp), reverse=True):
    for c in a[i]:
        if c == 's':
            cnt_s += 1
        else:
            ans += cnt_s
print(ans)
