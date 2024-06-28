import sys

input = lambda: sys.stdin.readline().rstrip()
n, s = map(int, input().split())
dep = [0] * n
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  dep[a] += 1
  dep[b] += 1

print(s / dep.count(1) * 2)
