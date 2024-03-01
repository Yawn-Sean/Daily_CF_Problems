n = int(input())
a = list(map(int, input().split()))

N = max(a) + 1

factors = [[] for _ in range(N)]
for i in range(1, N):
  for j in range(i, N, i):
    factors[j].append(i)

cnt = [0] * N
for i in a:
  cnt[i] += 1
for i in range(N - 1, 0, -1):
  cnt[i - 1] += cnt[i]

mod = 10 ** 9 + 7
res = 0
for i in range(1, N):
  tmp = 1
  k = len(factors[i])
  for j in range(1, k):
    tmp = tmp * pow(j, cnt[factors[i][j - 1]] - cnt[factors[i][j]], mod) % mod
  tmp = tmp * (pow(k, cnt[i], mod) - pow(k - 1, cnt[i], mod)) % mod
  res = (res + tmp) % mod
print(res)
