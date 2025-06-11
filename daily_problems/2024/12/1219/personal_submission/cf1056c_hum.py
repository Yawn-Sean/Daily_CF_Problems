n, m = map(int, input().split())
powers = [0] + list(map(int, input().split()))

prs = [0] * (2 * n + 1)
for _ in range(m):
  x, y = map(int, input().split())
  prs[x] = y
  prs[y] = x

used = [0] * (2 * n + 1)

t = int(input())
last = 0

for _ in range(n):
  if t == 2:
    last = int(input())
    used[last] = 1

  if last and prs[last] and not used[prs[last]]:
    print(prs[last], flush=True)
    used[prs[last]] = 1
  else:
    v, chosen = -1, 0
    for i in range(1, 2 * n + 1):
      if prs[i] and not used[i] and powers[i] - powers[prs[i]] > v:
        v = powers[i] - powers[prs[i]]
        chosen = i

    if not chosen:
      for i in range(1, 2 * n + 1):
        if not used[i] and powers[i] > v:
          v = powers[i]
          chosen = i

    print(chosen, flush=True)
    used[chosen] = 1

  if t == 1:
    last = int(input())
    used[last] = 1
