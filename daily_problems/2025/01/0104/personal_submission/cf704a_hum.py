n, q = map(int, input().split())

cnt = [0] * (n + 1)
unread = [0] * (n + 1)
stk = []
pt = 0
res = 0
for i in range(q):
  t, x = map(int, input().split())

  if t == 1:
    res += 1
    cnt[x] += 1
    stk.append(x)

  elif t == 2:
    res -= cnt[x]
    cnt[x] = 0
    unread[x] = len(stk)

  else:
    while pt < x:
      if pt >= unread[stk[pt]]:
        res -= 1
        cnt[stk[pt]] -= 1
      pt += 1

  print(res)
