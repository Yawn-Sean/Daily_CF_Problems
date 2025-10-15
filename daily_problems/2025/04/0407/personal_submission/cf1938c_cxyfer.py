from itertools import *

t = int(input())

for _ in range(t):
    n = int(input())
    A = list(map(int, input().split()))

    if n == 1:
        print((1 << A[0]) - 1)
        continue

    ans = (1 << A[0]) - 1

    for i, (x, y) in enumerate(pairwise(A), start=1):
        b = x - y + 1
        if b >= 0:
            ans = max(ans, (1 << (x + 1)) - (1 << b) - i)

    for i, x in enumerate(A):
        if (ans + i).bit_count() != x:
            ans = -1
            break
    print(ans)
