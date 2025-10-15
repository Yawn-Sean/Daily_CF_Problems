import math
 
n = int(input())
f = list(map(lambda x: int(x) - 1, input().split(" ")))
circle, minumum = 1, 1
for i in range(n):
    x, step = i, 1
    visit = {i: 1}
    while f[x] not in visit:
        x, step = f[x], step + 1
        visit[x] = step
    if f[x] == i:
        circle = circle * step // math.gcd(circle, step)
    else:
        minumum = max(minumum, visit[f[x]] - 1)
print((minumum + circle - 1) // circle * circle)