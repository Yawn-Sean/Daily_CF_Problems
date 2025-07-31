import sys
inp = iter(sys.stdin.read().split())

n = int(next(inp))
OP = []
mx = 0
pos = dict()
for i in range(n):
    op = next(inp)
    x = int(next(inp))
    OP.append((op, x))
    if op == 'sell':
        mx = max(mx, x)
        pos[x] = i

ans = 0
vis = [False] * n
for i in range(mx, -1, -1):
    if i not in pos.keys():
        continue
    p = pos[i]
    for j in range(p, -1, -1):
        if vis[j]:
            break
        if OP[j][0] == 'win' and OP[j][1] == i:
            ans += 1 << i
            for k in range(j, p + 1):
                vis[k] = True
            break
print(ans)
