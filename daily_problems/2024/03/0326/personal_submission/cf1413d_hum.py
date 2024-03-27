import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
q = []
for _ in range(2 * n):
  q.append(input())

stack = []
res = [0] * (2 * n)
for i, s in enumerate(q):
  if s == '+':
    stack.append(i)
  else:
    num = int(s.split(" ")[1])
    if len(stack) == 0:
      exit(print("NO"))
    res[stack.pop()] = num

h = []
for i, s in enumerate(q):
  if s == '+':
    heappush(h, res[i])
  else:
    num = int(s.split(" ")[1])
    if len(h) == 0 or h[0] != num:
      exit(print("NO"))
    heappop(h)

print("YES")
print(*[res[i] for i in range(2 * n) if res[i] != 0])
