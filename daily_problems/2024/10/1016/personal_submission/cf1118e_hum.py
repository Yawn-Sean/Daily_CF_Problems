n, k = map(int, input().split())
if k * (k - 1) < n:
  print("NO")
  exit()

print("YES")

cnt = 0
for i in range(k):
  for j in range(i + 1, k):
    print(i + 1, j + 1)
    cnt += 1
    if cnt == n:
      exit()
    print(j + 1, i + 1)
    cnt += 1
    if cnt == n:
      exit()
