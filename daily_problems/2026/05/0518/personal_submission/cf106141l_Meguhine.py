import sys
from fractions import Fraction

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
a = list(map(int, input().split()))
idx = sorted(range(n), key=lambda x: abs(a[x]))

p = sum(abs(x) for x in a) * 3
q = n * 9
mx, pivot = Fraction(p * p, q), 0  # [0, pivot) use 1

for i, j in enumerate(idx):
    p -= abs(a[j]) * 2
    q -= 8
    nw = Fraction(p * p, q)
    if nw > mx:
        mx, pivot = nw, i + 1

ans = [0] * n
for i in range(pivot):
    j = idx[i]
    ans[j] = 1 if a[j] > 0 else -1
for i in range(pivot, n):
    j = idx[i]
    ans[j] = 3 if a[j] > 0 else -3
print(' '.join(map(str, ans)))
