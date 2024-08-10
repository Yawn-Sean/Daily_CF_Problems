import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

def cbrt(n):
    left, right = 0, 1000001
    while left + 1 < right:
        mid = (left + right) >> 1
        if mid * mid * mid > n:
            right = mid
        else:
            left = mid
    return left

for _ in range(int(input())):
    a, b = map(int, input().split())
    print("No" if (c := cbrt(a * b)) ** 3 != a * b or a % c or b % c else "Yes")
