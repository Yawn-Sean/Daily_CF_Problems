import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  a, b = map(int, input().split())
  t = int((a * b) ** (1 / 3))
  if t * t * t == a * b:
    if a % t == 0 and b % t == 0:
      print("Yes")
      continue
  t += 1
  if t * t * t == a * b:
    if a % t == 0 and b % t == 0:
      print("Yes")
      continue
  print("No")
