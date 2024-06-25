import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

mod = 10 ** 9 + 7
n, m, k, r, c = MII()
a1, b1, a2, b2 = MII()

print(pow(k, n * m - r * c * (a1 != a2 or b1 != b2), mod))