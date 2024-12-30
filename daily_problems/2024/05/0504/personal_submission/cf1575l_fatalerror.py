import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from bisect import bisect_left

def solve():
    n = ii()
    arr = lii()
    diff = [(i-x, x) for i, x in enumerate(arr, 1) if i-x >= 0]
    diff.sort()
    lis = []
    for _, x in diff:
        if not lis or x > lis[-1]:
            lis.append(x)
        else:
            lis[bisect_left(lis, x)] = x
    return len(lis)

print(solve())
