import sys

input = lambda: sys.stdin.readline().rstrip()

ax, ay, bx, by = map(int, input().split())
base = abs(ax - bx) + abs(ay - by)

if ax == bx or ay == by:
    print(base)
    sys.exit(0)

if ax > bx:
    ax, ay, bx, by = bx, by, ax, ay
D = 1 if (ay < by) else -1


def sign(x: int, y: int, d: int, k: int) -> int:
    f = x * d + k
    if f == y:
        return 0
    return 1 if y > f else -1


ans = base
ps = ((ax, by), (bx, ay))
M = int(input())
for _ in range(M):
    k, d = map(int, input().split())
    if d != D:
        continue
    sign_a = sign(ax, ay, d, k)
    sign_b = sign(bx, by, d, k)
    if sign_a * sign_b <= 0:
        print(max(abs(ax - bx), abs(ay - by)))
        sys.exit(0)
    for px, py in ps:
        sign_p = sign(px, py, d, k)
        if sign_p * sign_a <= 0:
            ans = min(ans, base - abs(px * d + k - py))

print(ans)

"""
简单画一画图, 就能发现, 最多只会用一条直线
"""
