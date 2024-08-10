import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, k = map(int, input().split())
print((6 * n - 1) * k)
for i in range(n):
    print(f"{(6 * i + 1) * k} {(6 * i + 2) * k} {(6 * i + 3) * k} {(6 * i + 5) * k}")
