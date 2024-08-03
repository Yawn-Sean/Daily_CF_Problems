import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())


def check(nex):
  stack = []
  for i in range(len(nex)):
    while stack and i >= stack[-1]:
      stack.pop()
    if stack and nex[i] > stack[-1]:
      return False
    stack.append(nex[i])
  return True


for _ in range(t):
  n = int(input())
  nex = list(map(int, input().split()))
  nex = [nex[i] - 1 if nex[i] != -1 else i + 1 for i in range(n)]

  if not check(nex):
    print("-1")
    continue
  t = [[] for _ in range(n + 1)]
  for i, v in enumerate(nex):
    t[v].append(i)

  q = [n]
  i = 0
  while i < len(q):
    q.extend(t[q[i]])
    i += 1

  if len(q) != n + 1:
    print(-1)
    continue
  res = [0] * n
  for i in range(1, n + 1):
    res[q[i]] = n - i + 1

  print(*res)
