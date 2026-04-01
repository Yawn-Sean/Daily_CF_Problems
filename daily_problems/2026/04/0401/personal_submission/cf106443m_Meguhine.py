import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
a = sorted(map(int, input().split()))

if a[0] == a[-1]:
    print("0")
    sys.exit(0)

a += list(map(lambda x: x + m, a))
s = list(accumulate(a, initial=0))


# l, r are 0-index-based
def get(l: int, r: int) -> int:
    return s[r + 1] - s[l]


def calc(l: int, x: int) -> int:
    r = l + n - 1
    return a[x] * (x - l) - get(l, x - 1) + \
        get(x + 1, r) - a[x] * (r - x)


ans, l = 10**16, 0
for i in range(n << 1):
    res = calc(l, i)
    while l + 1 <= n:
        nres = calc(l + 1, i)
        if nres <= res:
            l += 1
            res = nres
        else:
            break
    ans = ans if ans < res else res

print(ans)
