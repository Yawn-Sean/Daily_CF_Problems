import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input())
    a = list(map(int, input().split()))
    pre = list(accumulate(a, initial=0))
    m = n // 2
    ans, s = 0, 0
    for x in range(1, m + 1):
        s += pre[-x] - pre[x - 1]
        ans += s / (n - x + 1)
        ans += s / x
    if n & 1:
        s += a[m]
        ans += s / (m + 1)
    return f"{ans * 2 / n / (n + 1):.12f}"


print('\n'.join(
    solve() for _ in range(int(input()))
))
