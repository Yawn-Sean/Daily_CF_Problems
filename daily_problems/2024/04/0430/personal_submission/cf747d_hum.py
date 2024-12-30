n, k = map(int, input().split())
a = list(map(int, input().split()))

cnt = 0
tmp = []
last = -1
for i in range(n):
  if a[i] < 0:
    cnt += 1
    if last != -1:
      tmp.append(i - last - 1)
    last = i

if cnt > k:
  print(-1)
  exit()

if cnt == 0:
  print(0)
  exit()

res = 2 * cnt
k -= cnt
tmp.sort()
for v in tmp:
  if k >= v:
    k -= v
    res -= 2

if n - last - 1 <= k:
  print(res - 1)
else:
  print(res)
