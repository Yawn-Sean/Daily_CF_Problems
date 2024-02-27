t = int(input())

for _ in range(t):
  n, l, r, s = map(int, input().split())
  m = r - l + 1
  if sum(range(1, m + 1)) > s or sum(range(n, n - m, -1)) < s:
    print(-1)
    continue
  cur = [i for i in range(1, m + 1)]
  cur_sum = sum(cur)
  for i in range(m - 1, -1, -1):
    need = s - cur_sum
    can = n - cur[i] - (m - 1 - i)
    cur[i] += min(can, need)
    cur_sum += min(can, need)

  ss = set(cur)
  res = []
  for i in range(1, n + 1):
    if i not in ss:
      res.append(i)
  res = res[:l - 1] + cur + res[l - 1:]
  print(*res)
