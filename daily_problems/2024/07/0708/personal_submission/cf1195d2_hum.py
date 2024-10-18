n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 11
for i in range(n):
  cnt[len(str(a[i]))] += 1

res = 0
mod = 998244353


def f(s1, s2):
  t1 = list(reversed(s1))
  t2 = list(reversed(s2))
  res = []
  i = 0
  while i < len(t1) or i < len(t2):
    if i < len(t1):
      res.append(t1[i])
    if i < len(t2):
      res.append(t2[i])
    i += 1
  return int(''.join(reversed(res)))


tmp = ['0' * i for i in range(11)]

for v in a:
  for i in range(1, 11):
    res = (res + f(str(v), tmp[i]) * cnt[i]) % mod
    res = (res + f(tmp[i], str(v)) * cnt[i]) % mod

print(res)
