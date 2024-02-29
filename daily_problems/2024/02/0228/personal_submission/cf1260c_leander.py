import sys
import math

input = lambda: sys.stdin.readline().strip()


T = int(input())
for _ in range(T):
    r, b, k = map(int, input().split())
    g = math.gcd(r, b)
    r //= g
    b //= g
    if b * (k - 1) + 1 < r or r * (k - 1) + 1 < b:
        print("REBEL")
    else:
        print("OBEY")



