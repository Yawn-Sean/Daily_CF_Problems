import sys

input = lambda: sys.stdin.readline().rstrip()
from math import pi

n = int(input())
circles = [list(map(int, input().split())) for _ in range(n)]
circles.sort(key=lambda x: -x[2])


def isin(x, y):
  return (circles[x][0] - circles[y][0]) ** 2 + (circles[x][1] - circles[y][1]) ** 2 <= (
      circles[x][2] - circles[y][2]) ** 2


times = [0] * n
for i in range(n):
  for j in range(i):
    if isin(i, j):
      times[i] += 1

res = 0
for i in range(n):
  if max(0, times[i] - 1) % 2:
    res -= circles[i][2] ** 2
  else:
    res += circles[i][2] ** 2

print(pi * res)
