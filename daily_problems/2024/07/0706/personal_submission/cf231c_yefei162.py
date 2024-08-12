import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())


tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    A = LI()
    A.sort()
    PA = list(accumulate(A, initial=0))

    ans = 0
    mode = 0
    for i, a in enumerate(A):
        L, R = 0, i + 1
        while L <= R:
            mid = (L + R) // 2
            if (i + 1 - mid) * a - (PA[i+1] - PA[mid]) <= k:
                tmp = mid
                R = mid - 1
            else:
                L = mid + 1
        if i + 1 - tmp > ans:
            ans = i + 1 - tmp
            mode = a

    print(ans, mode)
