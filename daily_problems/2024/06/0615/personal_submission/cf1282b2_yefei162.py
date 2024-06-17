# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())


tcn = I()
for _tcn_ in range(tcn):
    n, p, k = MI()
    A = LI()
    A.sort()
    A.insert(0, 0)
    for i in range(1, n + 1):
        if i < k:
            A[i] += A[i - 1]
        else:
            A[i] += A[i - k]
    ans = 0
    for i in range(n - 1, -1, -1):
        if A[i] <= p:
            ans = i
            break
    print(ans)
