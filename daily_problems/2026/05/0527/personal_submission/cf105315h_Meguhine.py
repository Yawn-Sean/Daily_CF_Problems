import sys
from array import array
from heapq import heapify, heappushpop
from itertools import islice

input = lambda: sys.stdin.readline().rstrip()


B = 18
MASK = (1 << B) - 1


def solve() -> str:
    n, k = map(int, input().split())
    a = array('i', [0] * n)
    b = array('q', [0] * n)
    for i in range(n):
        a[i], b[i] = map(int, input().split())
    idx = sorted(range(n), key=lambda x: b[x])
    p = [(a[i] << B | i) for i in islice(idx, k)]
    heapify(p)
    s = sum(a[i] for i in islice(idx, k))
    ans = s - b[idx[k - 1]]
    # print(f"{idx=} {ans=}", file=sys.stderr)
    # print(f"{list((a[i], b[i]) for i in islice(idx, n))}", file=sys.stderr)
    for i in islice(idx, k, n):
        j = heappushpop(p, a[i] << B | i) & MASK
        if i == j:
            continue
        else:
            s += a[i] - a[j]
            ans = max(ans, s - b[i])
    return str(ans)


print('\n'.join(
    solve() for _ in range(int(input()))
))
