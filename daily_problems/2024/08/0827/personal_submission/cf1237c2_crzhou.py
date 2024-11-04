n = II()
points = defaultdict(list)

for i in range(n):
    x, y, z = MII()
    points[x].append((y, z, i + 1))

res = []
tmpz = []
tmp = []

for x in points.keys():
    points[x].sort()
    l = len(points[x])
    j = 0
    vis = set()
    
    while j < l - 1:
        if points[x][j][0] == points[x][j + 1][0]:
            tmpz.append((points[x][j][2], points[x][j + 1][2]))
            vis.add(points[x][j][2])
            vis.add(points[x][j + 1][2])
            j += 2
        else:
            j += 1

    remaining = []
    for y, z, i in points[x]:
        if i not in vis:
            remaining.append((y, z, i))
    
    for i in range(0, len(remaining) - 1, 2):
        res.append((remaining[i][2], remaining[i + 1][2]))
    
    if len(remaining) % 2 == 1:
        tmp.append((x, remaining[-1][2]))

tmp.sort()
for i in range(0, len(tmp) - 1, 2):
    res.append((tmp[i][1], tmp[i + 1][1]))

for pair in tmpz:
    print(pair[0], pair[1])

for pair in res:
    print(pair[0], pair[1])
