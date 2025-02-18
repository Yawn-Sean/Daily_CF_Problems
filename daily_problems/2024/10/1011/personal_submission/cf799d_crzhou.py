N = int(1e5) + 5
a, b, h, w, n = MII()
val = [0] + LII()

val = sorted(val[1:], reverse=True)
lim = min(34, n)  # 最大操作次数
hii = (divi(a, h), divi(b, w))
wii = (divi(a, w), divi(b, h))
v = {} 
v[hii] = v[wii] = 1

q = deque([hii, wii])
while q:
    now = q.popleft()
    step = v[now]
    if now[0] == 1 and now[1] == 1:
        print(step - 1)
        exit(0)
    if step > lim:
        continue
    nxt = adjust((divi(now[0], val[step-1]), now[1]))
    if nxt not in v:
        v[nxt] = step + 1
        q.append(nxt)
    
    nxt = adjust((now[0], divi(now[1], val[step-1])))
    if nxt not in v:
        v[nxt] = step + 1
        q.append(nxt)

print(-1)
