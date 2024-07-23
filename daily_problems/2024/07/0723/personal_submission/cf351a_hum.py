from math import inf

n = int(input())
s = input().split()
a = [int(c.split(".")[1]) for c in s]

acc = sum(a)

cnt = a.count(0)
m = 2 * n - cnt
res = inf

for i in range(m + 1):
  if i + cnt >= n >= i:
    res = min(res, abs(acc - i * 1000))

print(f'{res / 1000:.3f}')
