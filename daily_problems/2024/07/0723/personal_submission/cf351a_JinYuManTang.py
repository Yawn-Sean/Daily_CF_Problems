from fractions import Fraction
import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
a = [Fraction('.' + x.split('.')[1]) for x in list(input().split())]
cnt = sum(x.numerator == 0 for x in a)
s = sum(a)
res = min(abs(x - s) for x in range(max(n - cnt, 0), min(2 * n - cnt, n) + 1))
print(f"{res.numerator / res.denominator:.3f}")
