import sys

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
cs = list(map(int, input().split()))
ps = list(map(float, input().split()))
for i in range(n):
    cs[i] += i


def f(x: float) -> float:
    x += n
    for c, p in zip(reversed(cs), reversed(ps)):
        sub = p * (x - c)
        if sub > 0:
            x -= sub
    return x


l, r = 0, 10**12
for _ in range(100):
    x = (l + r) / 2
    if f(x) > x:
        l = x
    else:
        r = x
print(f"{(l + r) / 2:.12f}")
