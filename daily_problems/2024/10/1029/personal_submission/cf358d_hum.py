n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
dp0, dp1 = a[0], b[0]
for i in range(1, n):
  dp0, dp1 = max(dp0 + b[i], dp1 + a[i]), max(dp0 + c[i], dp1 + b[i])

print(dp0)
