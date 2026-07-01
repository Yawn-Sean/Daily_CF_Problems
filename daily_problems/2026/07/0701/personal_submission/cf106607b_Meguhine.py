import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n = int(input())
    a = list(map(int, input().split()))
    if max(a) == 1:
        return "0"
    for l in range(n):
        if a[l] == 1:
            continue
        for r in range(l + 1, n):
            if a[r] == 1:
                return "1" if max(a[r:]) == 1 else "2"
            if a[l] != a[r]:
                return "2"
        else:
            return "1"
    assert False, "Unreachable"


print('\n'.join(solve() for _ in range(int(input()))))
