import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 只需考虑插入1和x的影响

t = II()
ans = []
for _ in range(t):
    n, x = MII()
    a = LMII()
    res = sum(abs(a[i] - a[i + 1]) for i in range(n - 1))
    mx, mn = max(a), min(a)
    up = min(abs(x - a[0]), abs(x - a[-1]), (0 if mx > x else (x - mx) * 2))
    down = min(abs(a[0] - 1), abs(a[-1] - 1), (mn - 1) * 2)
    ans.append(res + up + down)
print(*ans, sep='\n')