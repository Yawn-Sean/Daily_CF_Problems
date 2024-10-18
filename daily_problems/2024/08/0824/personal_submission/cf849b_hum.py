n = int(input())
a = list(map(int, input().split()))

for i in range(3):
  for j in range(i):
    if i == j:
      continue
    k = 2 * (a[j] - a[i]) // (j - i)
    b = set()
    for idx in range(n):
      b.add(a[idx] * 2 - k * idx)
    if len(b) == 2:
      print('Yes')
      exit()

print("No")
