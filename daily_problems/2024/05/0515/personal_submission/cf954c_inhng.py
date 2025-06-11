import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
a = list(map(int, input().split()))
col = 10 ** 9
for i in range(n - 1):
    if not abs(a[i + 1] - a[i]):
        exit(print("NO"))
    if abs(a[i + 1] - a[i]) > 1:
        col = abs(a[i + 1] - a[i])

col = 10 ** 9 if col == -1 else col
for i in range(n - 1):
    x1, y1 = divmod(a[i] - 1, col)
    x2, y2 = divmod(a[i+1] - 1, col)
    if abs(x1 - x2) + abs(y1 - y2) > 1:
        exit(print("NO"))

print("YES")
print(10 ** 9, col)
