import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


MOD = 10**9 + 7
N = 10**5 + 5
fc = list(accumulate(
    range(1, N),
    lambda pre, x: pre * x % MOD,
    initial=1
))
d = [1] * N
d[0] = d[1] = 0
for x in range(2, N):
    for y in range(x << 1, N, x):
        d[y] += 1
for i in range(1, N):
    d[i] += d[i - 1]


def solve() -> str:
    n = int(input())
    return str(d[n] * (n * (n - 1) >> 1) * fc[n - 2] % MOD)


print('\n'.join(solve() for _ in range(int(input()))))
