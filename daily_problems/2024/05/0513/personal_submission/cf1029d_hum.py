import sys

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
a = list(map(int, input().split()))


def f():
  cnt = [dict() for i in range(11)]
  res = 0
  t = [1]
  for i in range(11):
    t.append(t[-1] * 10 % k)
  for i in range(n):
    for j in range(1, 11):
      res += cnt[j].get((-a[i] * t[j]) % k, 0)
    cnt[len(str(a[i]))][a[i] % k] += 1
  return res


res = f()
a.reverse()
res += f()

print(res)
