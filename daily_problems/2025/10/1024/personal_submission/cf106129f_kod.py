h, w = il()
g = []
for i in range(h):
    s = [1 if x == "#" else 0 for x in ip()]
    g += s,
s = sum(sum(x) for x in g)
t = [[0] * w for _ in range(h)]
for i in range(min(h, w), 0, -1):
    if s % (i * i) == 0:
        # t = deepcopy(g) # deepcopy 导致超时，不如手动复制。。。
        for x in range(h):
            for y in range(w):
                t[x][y] = g[x][y]
        for x in range(h):
            for y in range(w):
                if t[x][y]:
                    for xx in range(x, x + i):
                        for yy in range(y, y + i):
                            if xx >= h or yy >= w or t[xx][yy] == 0:
                                break
                            t[xx][yy] = 0
                        else: continue
                        break
                    else: continue
                    break
            else: continue
            break
        else:  exit(print(i))
