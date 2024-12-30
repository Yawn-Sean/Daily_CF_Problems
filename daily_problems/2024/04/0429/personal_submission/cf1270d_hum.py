from collections import Counter


def query(a):
  print('?', *a, flush=True)
  return map(int, input().split())


n, k = map(int, input().split())

cnt = Counter()

for i in range(1, k + 2):
  idx, val = query((j for j in range(1, k + 2) if j != i))
  cnt[val] += 1

print('!', cnt[max(cnt)])
