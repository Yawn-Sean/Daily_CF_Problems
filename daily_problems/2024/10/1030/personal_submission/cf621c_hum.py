import sys

input = lambda: sys.stdin.readline().rstrip()
n, p = map(int, input().split())
t = []
for _ in range(n):
  a, b = map(int, input().split())
  t.append((b // p - (a - 1) // p) / (b - a + 1))

acc = 0
for i in range(n):
  acc += t[i] + t[(i + 1) % n] - t[i] * t[(i + 1) % n]

print(acc * 2000)
