n = II()
grid = [I() for _ in range(n)]

m = II()
ps = LGMI()

f = [[inf] * n for _ in range(n)]

for i in range(n):
   for j in range(n):
       if grid[i][j] == '1':
           f[i][j] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            if j != i:
                f[i][j] = min(f[i][j], f[i][k] + f[k][j])

ans = [ps[0] + 1]
pre = 0
cur = 1
while cur < m:
    while cur < m and f[ps[pre]][ps[cur]] == cur - pre:
        cur += 1
    pre = cur - 1
    ans.append(ps[pre] + 1)

print(len(ans))
print(' '.join(map(str, ans)))
