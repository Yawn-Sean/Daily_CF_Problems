n = int(input())
a = list(map(int, input().split()))
a.append(0)
d = [a[0]]
t = d[0]
for i in range(1, n + 1):
  d.append(a[i] - t)
  t += d[i]
res1 = []
res2 = []
for i in range(n + 1):
  if d[i] > 0:
    res1.append(i)
  elif d[i] < 0:
    res2.append(i)


i = 0
j = 0
res = []
while i < len(res1) and j < len(res2):
  res.append((res1[i] + 1, res2[j]))
  d[res1[i]] -= 1
  d[res2[j]] += 1
  if d[res1[i]] == 0:
    i += 1
  if d[res2[j]] == 0:
    j += 1

print(len(res))
for i in range(len(res)):
  print(res[i][0], res[i][1])
