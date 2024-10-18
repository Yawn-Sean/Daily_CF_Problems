from math import gcd
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# x * y = a * b，且a，b大于等于x，小于等于y
# 同除最大公约数太妙了

l, r, x, y = MII()
if y % x: # 不合法
    print(0)
elif x == y:
    print(1 if l <= x <= r else 0)
else:
    v = y // x # 然后进行分解互质对
    ans = 0
    for i in range(1, 10 ** 5):
        if i * i >= v:
            break
        if v % i == 0 and gcd(i, v // i) == 1 and l <= i * x <= r and l <= v // i * x <= r:
            ans += 2
    print(ans)