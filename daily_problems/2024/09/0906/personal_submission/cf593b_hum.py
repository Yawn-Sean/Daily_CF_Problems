import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
x1, x2 = map(int, input().split())
tmp = []
for _ in range(n):
  k, b = map(int, input().split())

  tmp.append((k * x1 + b, k * x2 + b))

tmp.sort()

for i in range(1, n):
  if tmp[i][1] < tmp[i - 1][1]:
    print("YES")
    exit()

print("NO")
