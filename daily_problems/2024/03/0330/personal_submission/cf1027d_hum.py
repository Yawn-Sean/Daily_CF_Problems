n = int(input())
c = list(map(int, input().split()))
a = list(map(lambda x: int(x) - 1, input().split()))

cnt = 0
col = [0] * n
res = 0
for i in range(n):
  if col[i] == 0:
    cnt += 1
    stack = [i]
    col[i] = cnt
    u = i
    while True:
      v = a[u]
      if col[v] == 0:
        col[v] = cnt
        stack.append(v)
        u = v
      elif col[v] == cnt:
        tmp = c[v]
        while stack[-1] != v:
          tmp = min(tmp, c[stack.pop()])
        res += tmp
        break
      else:
        break

print(res)
