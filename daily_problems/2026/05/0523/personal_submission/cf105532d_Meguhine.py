import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
a = list(sorted(map(int, input().split())) for _ in range(n))


def check(x: int) -> bool:
    s = 0
    for l, r in a:
        if l >= x:
            s += r
        elif r >= x:
            s += l
    return s >= x


l, r, ans = 2, 10**9, 1
while l <= r:
    mid = (l + r) >> 1
    if check(mid):
        ans = mid
        l = mid + 1
    else:
        r = mid - 1
print(ans)
