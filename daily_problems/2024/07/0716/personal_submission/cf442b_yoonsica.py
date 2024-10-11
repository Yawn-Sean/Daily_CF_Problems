import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RIF = lambda: map(float, sys.stdin.readline().strip().split())
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
RFLIST = lambda: list(RIF())

n = RI()
a = RFLIST()
ans = 0
p0, p1 = 1, 0  # 没人作出，恰有1人的概率
for x in sorted(a)[::-1]:
    p1 = p0 * x + p1 * (1 - x)
    p0 *= 1 - x
    ans = max(ans, p1)
print(ans)
