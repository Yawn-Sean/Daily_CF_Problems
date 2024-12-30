import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
xl, yl, xr, yr = [], [], [], []

for i in range(n):
  x1, y1, x2, y2 = map(int, input().split())
  xl.append(x1)
  yl.append(y1)
  xr.append(x2)
  yr.append(y2)

pref_xl_max = xl[:]
pref_yl_max = yl[:]
pref_xr_min = xr[:]
pref_yr_min = yr[:]

for i in range(1, n):
  pref_xl_max[i] = max(pref_xl_max[i], pref_xl_max[i - 1])
  pref_yl_max[i] = max(pref_yl_max[i], pref_yl_max[i - 1])
  pref_xr_min[i] = min(pref_xr_min[i], pref_xr_min[i - 1])
  pref_yr_min[i] = min(pref_yr_min[i], pref_yr_min[i - 1])

suff_xl_max = xl[:]
suff_yl_max = yl[:]
suff_xr_min = xr[:]
suff_yr_min = yr[:]

for i in range(n - 2, -1, -1):
  suff_xl_max[i] = max(suff_xl_max[i], suff_xl_max[i + 1])
  suff_yl_max[i] = max(suff_yl_max[i], suff_yl_max[i + 1])
  suff_xr_min[i] = min(suff_xr_min[i], suff_xr_min[i + 1])
  suff_yr_min[i] = min(suff_yr_min[i], suff_yr_min[i + 1])

if pref_xl_max[n - 2] <= pref_xr_min[n - 2] and pref_yl_max[n - 2] <= pref_yr_min[n - 2]:
  print(pref_xl_max[n - 2], pref_yl_max[n - 2])

elif suff_xl_max[1] <= suff_xr_min[1] and suff_yl_max[1] <= suff_yr_min[1]:
  print(suff_xl_max[1], suff_yl_max[1])

else:
  for i in range(1, n - 1):
    if max(pref_xl_max[i - 1], suff_xl_max[i + 1]) <= min(pref_xr_min[i - 1], suff_xr_min[i + 1]) and max(
        pref_yl_max[i - 1], suff_yl_max[i + 1]) <= min(pref_yr_min[i - 1], suff_yr_min[i + 1]):
      print(max(pref_xl_max[i - 1], suff_xl_max[i + 1]), max(pref_yl_max[i - 1], suff_yl_max[i + 1]))
      break
