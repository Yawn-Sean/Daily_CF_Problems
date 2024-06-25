import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())

op_map = dict(zip("AONX", [2, 3, 4, 5]))
ops = [-1] * n
tree = [[] for _ in range(n)]
parent = [-1] * n

for i in range(n):
  op, *vals = input().split()
  if op[0] == 'I':
    ops[i] = int(vals[0])
  else:
    vals = [int(x) - 1 for x in vals]
    tree[i] = vals
    for v in vals:
      parent[v] = i
    ops[i] = op_map[op[0]]

order = []
stack = [0]
while stack:
  u = stack.pop()
  order.append(u)
  for v in tree[u]:
    stack.append(v)

res = [-1] * n

for i in reversed(order):
  if len(tree[i]) == 0:
    res[i] = ops[i]
  else:
    if ops[i] == 2:
      res[i] = res[tree[i][0]] & res[tree[i][1]]
    elif ops[i] == 3:
      res[i] = res[tree[i][0]] | res[tree[i][1]]
    elif ops[i] == 4:
      res[i] = res[tree[i][0]] ^ 1
    else:
      res[i] = res[tree[i][0]] ^ res[tree[i][1]]

reverse_note = [0] * n
reverse_note[0] = 1

stack = [0]

while stack:
  u = stack.pop()
  if ops[u] == 2:
    v, w = tree[u]
    if res[u] == 0:
      if res[v]:
        stack.append(w)
        reverse_note[w] = 1
      elif res[w]:
        stack.append(v)
        reverse_note[v] = 1
    else:
      stack.append(v)
      stack.append(w)
      reverse_note[v] = reverse_note[w] = 1
  elif ops[u] == 3:
    v, w = tree[u]
    if res[u] == 1:
      if res[v] == 0:
        stack.append(w)
        reverse_note[w] = 1
      elif res[w] == 0:
        stack.append(v)
        reverse_note[v] = 1
    else:
      stack.append(v)
      stack.append(w)
      reverse_note[v] = reverse_note[w] = 1

  else:
    for v in tree[u]:
      stack.append(v)
      reverse_note[v] = 1

print(''.join(str(reverse_note[i] ^ res[0]) for i in range(n) if len(tree[i]) == 0))
