import sys

input = lambda: sys.stdin.readline().rstrip()


def solve() -> str:
    n, ca, cb = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if a[0] < b[0]:
        return "0"
    da = [0] * n
    for i, x in enumerate(a):
        da[x >> 1] = i * ca
    db = [0] * n
    for i, x in enumerate(b):
        db[(x - 1) >> 1] = i * cb
    ans = mn = 10**15
    for x, y in zip(da, db):
        mn = min(x, mn)
        ans = min(ans, mn + y)
    return str(ans)


print('\n'.join(solve() for _ in range(int(input()))))
