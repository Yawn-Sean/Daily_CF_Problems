n = int(input())
xs, ys = [], []
for _ in range(n):
    x, y = map(int,input().split())
    xs.append(x)
    ys.append(y)
ans = 0
opt = 2 * 10 ** 9 +1
dic = {}
for i in range(n):
    x, y = xs[i], ys[i]
    for j in range(i):
        xj, yj = xs[j], ys[j]
        if ((x + xj) * opt  + (y + yj)) not in dic:
            dic[((x + xj) * opt + (y + yj))] = 0     
        ans += dic[((x + xj) * opt + (y + yj))]
        dic[((x + xj) * opt + (y + yj))] += 1
print(ans)
