import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  input()
  n = int(input())
  cnt = [0] * n
  for i in range(n):
    s = input()
    for j in range(n):
      if s[j] == '1':
        cnt[(i - j) % n] += 1
  print(n + sum(cnt) - 2 * max(cnt))
