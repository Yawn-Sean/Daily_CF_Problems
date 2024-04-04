def query(i, j):
  print("?", i, j, flush=True)
  return int(input())


n = int(input())

t1 = []
for i in range(n):
  t1.append(query(0, i))

t2 = [t1[0]]
for i in range(1, n):
  t2.append(query(i, 0))

res = []
cnt = 0
for i in range(n):
  p = [0] * n
  b = [0] * n
  for j in range(n):
    b[j] = i ^ t1[j]

  for j in range(n):
    p[j] = b[0] ^ t2[j]

  for j in range(n):
    if not (b[j] < n and p[b[j]] == j):
      break
  else:
    cnt += 1
    res = p

print("!")
print(cnt)
print(*res)
