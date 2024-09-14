n, mx = MII()
q = deque()
cur = 0
ans = [-1] * n
qs = [LII() for _ in range(n)]
cur = ans[0] = qs[0][0] + qs[0][1]

i = 1
while i < n:
    a, b = qs[i]
    if len(q) < mx and a <= cur:
        q.append((a, b, i))
        i += 1
        continue
    elif len(q) == mx and a < cur:
        i += 1
        continue
    q.append((a, b, i))
    x, y, j = q.popleft()
    cur = max(cur, x)
    cur += y
    ans[j] = cur
    i += 1

while q:
    x, y, j = q.popleft()
    cur = max(cur, x)
    cur += y
    ans[j] = cur
    
print(*ans)
