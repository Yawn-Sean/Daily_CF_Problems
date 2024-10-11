n, s = map(int, input().split())
s -= 1
a = list(map(int, input().split()))

res = 0
if a[s] != 0:
  res += 1

a = a[:s] + a[s + 1:]
for i in range(n - 1):
  if a[i] == 0:
    a[i] = n + 1

a.sort()

j = 0
for u in range(1, n):
  if j == len(a):
    break
  if a[j] != u:
    res += 1
    a.pop()
  else:
    while j < len(a) and a[j] == u:
      j += 1

print(res)
