import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

output = []

for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    ans = sum(abs(a[i] - a[i + 1]) for i in range(n - 1))
    mx, mn = max(a), min(a)
    up = min(abs(x - a[0]), abs(x - a[-1]), (0 if mx > x else (x - mx) * 2))
    down = min(abs(a[0] - 1), abs(a[-1] - 1), (mn - 1) * 2)
    output.append(ans + up + down)

print('\n'.join(map(str, output)))
