import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

mod = 10 ** 9 + 7
A, B, n, x = MII()

# 处理逆元，只要mod是质数就行

if A == 1:
    print((x + n * B) % mod)
else:
    t = pow(A, n, mod)
    print(((x * t) + (t - 1) * B * pow(A - 1, mod - 2, mod)) % mod)

