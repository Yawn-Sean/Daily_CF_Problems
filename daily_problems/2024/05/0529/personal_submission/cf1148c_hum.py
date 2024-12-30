n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
pos = [0] * n
for i in range(n):
  pos[a[i]] = i

res = []


def s(i, j):
  res.append((i + 1, j + 1))
  pos[a[i]], pos[a[j]] = pos[a[j]], pos[a[i]]
  a[i], a[j] = a[j], a[i]


for i in range(n):
  if pos[i] != i:
    if 2 * abs(pos[i] - i) >= n:
      s(i, pos[i])
    elif i < n // 2:
      if pos[i] >= n // 2:
        s(0, n - 1)
        s(pos[i], 0)
        s(0, n - 1)
        s(i, n - 1)
      else:
        s(pos[i], n - 1)
        s(i, n - 1)
    else:
      s(0, i)
      s(0, pos[i])
      s(0, i)

print(len(res))
for i in res:
  print(*i)
