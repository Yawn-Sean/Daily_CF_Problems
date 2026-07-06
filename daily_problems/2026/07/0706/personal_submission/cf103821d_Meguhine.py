import sys
from math import isqrt

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input()) + 1
    m = isqrt(n)
    if m * m != n:
        return "-1"
    return f"{m - 1}\n{' '.join(map(str, range(1, m)))}"


print('\n'.join(solve() for _ in range(int(input()))))
