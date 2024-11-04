n, T = MII()
ps = []
for i in range(n):
    x, y = MII()
    if y > T:
        continue
    ps.append((y, x, i + 1))

ps.sort()

def check(t: int) -> bool:
    res = 0
    curt = 0
    for y, x, _ in ps:
        if x < t:
            continue
        if curt + y > T:
            break
        curt += y
        res += 1
    return res < t

ans = bisect_left(range(n + 1), True, key=check) - 1

outs = []
res = 0
curt = 0
for y, x, i in ps:
    if x < ans:
        continue
    if curt + y > T or res == ans:
        break
    curt += y
    res += 1
    outs.append(i)
print(ans)
print(res)
print(' '.join(map(str, outs)))
