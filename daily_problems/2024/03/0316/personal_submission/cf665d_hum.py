n = int(input())
a = list(map(int, input().split()))
m = max(a)
is_p = [-1] * (2 * m + 1)
for i in range(2, 2 * m + 1):
  if is_p[i] == -1:
    is_p[i] = 1
  for j in range(i + i, 2 * m + 1, i):
    is_p[j] = 0

cnt1 = a.count(1)

if cnt1 >= 2:
  for v in a:
    if v == 1:
      continue
    if is_p[v + 1] == 1:
      print(cnt1 + 1)
      print(" ".join(["1"] * cnt1 + [str(v)]))
      exit()

  print(cnt1)
  print(" ".join(["1"] * cnt1))
  exit()
else:
  for i in range(n):
    for j in range(i):
      if is_p[a[i] + a[j]] == 1:
        print(2)
        print(a[i], a[j])
        exit()

print(1)
print(a[0])
