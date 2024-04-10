from math import inf

n, m = map(int, input().split())
a = list(map(int, input().split()))
a = [(v, 0) for v in a]
b = list(map(int, input().split()))
b = [(v, 1) for v in b]
c = a + b
c.sort()
s1, s2 = [0], [0]

for i in range(n + m):
  s1.append(s1[-1])
  s2.append(s2[-1])
  if c[i][1] == 0:
    s1[-1] += c[i][0]
  else:
    s2[-1] += c[i][0]

cnt1, cnt2 = 0, 0
res = inf
for i in range(n + m):
  if c[i][1] == 0:
    cnt1 += 1
  else:
    cnt2 += 1

  t1 = cnt1 * c[i][0] - (s1[i + 1] - s1[0])
  t2 = (s2[-1] - s2[i + 1]) - (m - cnt2) * c[i][0]
  res = min(res, t1 + t2)
print(res)
