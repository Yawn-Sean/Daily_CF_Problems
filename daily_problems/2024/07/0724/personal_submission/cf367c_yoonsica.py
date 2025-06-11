import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())


def f(x):
    return x * (x + 1) // 2 + 1 if x % 2 == 0 else x * (x + 1) // 2 + x // 2 + 1


n, m = RII()
nums = []

for _ in range(m):
    _, x = RII()
    nums.append(x)

nums.sort(reverse=True)
ans = 0

for i in range(m):
    if f(i) > n:
        break
    ans += nums[i]

print(ans)