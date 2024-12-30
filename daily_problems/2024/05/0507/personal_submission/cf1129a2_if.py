tar = 10000
n, m = map(int, input().split())
d = [[tar, 0] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    d[a-1][1] += 1
    
    d[a-1][0] = min(d[a-1][0], (b-a)%n)
ans= []
for i in range(n):
    c = 0
    for j in range(n):
        a = (i+j)%n
        x, y = d[a][0], d[a][1]
        if y == 0:
            continue
        c = max(c, (y-1)*n + j + x)
    ans.append(c)
print(' '.join(map(str, ans)))
