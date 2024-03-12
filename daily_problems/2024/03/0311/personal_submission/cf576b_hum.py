n = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))

for i in range(n):
  if p[i] == i:
    print("YES")
    for j in range(n):
      if i != j:
        print(i + 1, j + 1)
    exit()

col = [-1] * n
x, y = -1, -1
for i in range(n):
  size = 0
  j = i
  while col[j] == -1:
    col[j] = size & 1
    j = p[j]
    size += 1
  if size % 2:
    print("NO")
    exit()
  if size == 2:
    x, y = i, p[i]

if x != -1:
  print("YES")
  print(x + 1, y + 1)
  for i in range(n):
    if i == x or i == y:
      continue
    if col[i] == 0:
      print(x + 1, i + 1)
    else:
      print(y + 1, i + 1)
else:
  print("NO")
