import math
import sys

input = lambda: sys.stdin.readline().rstrip()
MI = lambda: map(int, input().split())


A = [1, 1, 1, 2, 9]

tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    tot = 1
    for i in range(2, k + 1):
        tot += math.comb(n, i) * A[i]
    print(tot)
