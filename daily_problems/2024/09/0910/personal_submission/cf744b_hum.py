from math import inf

n = int(input())
k = n.bit_length()

saved0 = [[0] * k for _ in range(n)]
saved1 = [[0] * k for _ in range(n)]

for bit in range(k):
  tmp = [i for i in range(1, n + 1) if i >> bit & 1 == 0]
  print(len(tmp))
  print(*tmp, flush=True)
  res = list(map(int, input().split()))
  for j in range(n):
    saved0[j][bit] = res[j]

  tmp = [i for i in range(1, n + 1) if i >> bit & 1]
  print(len(tmp))
  print(*tmp, flush=True)
  res = list(map(int, input().split()))
  for j in range(n):
    saved1[j][bit] = res[j]

res = [inf] * n
for i in range(n):
  for bit in range(k):
    if (i + 1) >> bit & 1:
      res[i] = min(res[i], saved0[i][bit])
    else:
      res[i] = min(res[i], saved1[i][bit])

print(-1)
print(*res)
