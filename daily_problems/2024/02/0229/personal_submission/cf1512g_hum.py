N = 10 ** 7 + 1
tmp = [1] * N
vis = [False] * N
pr = []
for i in range(2, N):
  if not vis[i]:
    pr.append(i)
    tmp[i] = i + 1
  for p in pr:
    if (t := p * i) >= N:
      break
    vis[t] = True
    if i % p == 0:
      tmp[t] = tmp[i] + (tmp[i] - tmp[i // p]) * p
      break
    tmp[t] = tmp[i] * (1 + p)

res = [-1] * N
for i in range(N - 1, 0, -1):
  if tmp[i] < N:
    res[tmp[i]] = i

q = int(input())
for _ in range(q):
  print(res[int(input())])
