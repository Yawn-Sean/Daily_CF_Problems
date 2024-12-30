import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
a = list(map(int, input().split()))

stack = []
for _ in range(m):
  t, r = map(lambda x: int(x) - 1, input().split())
  while stack and stack[-1][1] <= r:
    stack.pop()
  stack.append((t, r))

res = a[:]
tmp = sorted(a[:stack[0][1] + 1])

stack.append((0, -1))

l, r = 0, stack[0][1]
end = stack[0][1]
for i in range(len(stack) - 1):
  length = stack[i][1] - stack[i + 1][1]
  if stack[i][0] == 0:
    for j in range(length):
      res[end] = tmp[r]
      end -= 1
      r -= 1
  else:
    for j in range(length):
      res[end] = tmp[l]
      end -= 1
      l += 1

print(*res)
