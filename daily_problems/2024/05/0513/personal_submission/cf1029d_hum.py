n, k = map(int, input().split())
a = list(map(int, input().split()))


def f():
  cnt = [defaultdict(int) for _ in range(11)]
  ans = 0
  t = [1]
  for i in range(10):
    t.append(t[-1] * 10 % k)
  for x in a:
    for j in range(1, 11):
      ans += cnt[j].get((-x * t[j]) % k, 0)
    cnt[len(str(x))][x % k] += 1
  return ans


res = f()
a.reverse()
res += f()

print(res)
