import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())

def f():
  n, m = map(int, input().split())

  a = []
  for _ in range(n):
    a.append(input())

  cnt_a = 0
  row = [0] * n
  col = [0] * m
  for i in range(n):
    for j in range(m):
      if a[i][j] == 'A':
        cnt_a += 1
        row[i] += 1
        col[j] += 1

  if cnt_a == n * m:
    print(0)
    return
  if cnt_a == 0:
    print("MORTAL")
    return

  if row[0] == m or row[-1] == m or col[0] == n or col[-1] == n:
    print(1)
    return

  if a[0][0] == 'A' or a[-1][-1] == 'A' or a[-1][0] == 'A' or a[0][-1] == 'A':
    print(2)
    return
  for i in range(1, n - 1):
    if row[i] == m:
      print(2)
      return
  for j in range(1, m - 1):
    if col[j] == n:
      print(2)
      return

  if row[0] + row[-1] + col[0] + col[-1] >= 1:
    print(3)
    return

  print(4)


for _ in range(t):
  f()
