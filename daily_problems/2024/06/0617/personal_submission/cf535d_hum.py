from itertools import accumulate

n, m = map(int, input().split())
s = input()
if m:
  a = list(map(lambda x: int(x) - 1, input().split()))


def z_function(s):
  n = len(s)
  z = [0] * n
  l, r = 0, 0
  for i in range(1, n):
    if i <= r and z[i - l] < r - i + 1:
      z[i] = z[i - l]
    else:
      z[i] = max(0, r - i + 1)
      while i + z[i] < n and s[z[i]] == s[i + z[i]]:
        z[i] += 1
    if i + z[i] - 1 > r:
      l = i
      r = i + z[i] - 1
  return z


z_res = z_function(s)

p = len(s)
f = [0] * p
for i in range(p):
  if z_res[i] == p - i:
    f[i] = 1

diff = [0] * (n + 1)

last = -p
for i in range(m):
  diff[a[i]] += 1
  diff[a[i] + p] -= 1
  if a[i] <= last + p - 1 and not f[a[i] - last]:
    print(0)
    exit()
  last = a[i]

d = list(accumulate(diff[:n]))

c = d.count(0)
print(pow(26, c, 10 ** 9 + 7))
