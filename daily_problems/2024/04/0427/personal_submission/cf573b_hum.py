n = int(input())
h = list(map(int, input().split()))
a = [1] * n
for i in range(1, n - 1):
  a[i] = min(a[i - 1] + 1, h[i])

for i in range(n - 2, -1, -1):
  a[i] = min(a[i + 1] + 1, a[i])

print(max(a))
