from math import gcd

x, y = map(int, input().split())

print(gcd(x - 1, y - 1) + 1)
