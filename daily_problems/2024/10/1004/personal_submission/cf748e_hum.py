n, k = map(int, input().split())
a = list(map(int, input().split()))
M = 10 ** 7
cnt = [0] * (M + 1)
for x in a:
  cnt[x] += 1

acc = 0
for i in range(M, 0, -1):
  acc += cnt[i]
  if i * 2 + 1 <= M:
    acc += cnt[i * 2 + 1]
    cnt[i] += cnt[i * 2 + 1]
    cnt[i + 1] += cnt[i * 2 + 1]

  if i * 2 <= M:
    acc += cnt[i * 2]
    cnt[i] += cnt[i * 2] * 2

  if acc >= k:
    print(i)
    exit()

print(-1)
