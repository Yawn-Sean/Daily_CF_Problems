n, T = map(int, input().split())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
t = [x - T for x in t]

res = sum(a)
tot_temp = sum(a[i] * t[i] for i in range(n))

idx = sorted(range(n), key=lambda x: t[x])

if tot_temp > 0:
  for ii in range(n - 1, -1, -1):
    i = idx[ii]
    if a[i] * t[i] <= tot_temp:
      tot_temp -= a[i] * t[i]
      res -= a[i]
    else:
      res -= tot_temp / t[i]
      tot_temp = 0
    if tot_temp == 0:
      break


elif tot_temp < 0:
  tot_temp = -tot_temp
  for ii in range(n):
    i = idx[ii]
    if a[i] * -t[i] <= tot_temp:
      tot_temp -= a[i] * -t[i]
      res -= a[i]
    else:
      res -= tot_temp / -t[i]
      tot_temp = 0
    if tot_temp == 0:
      break

print(res)
