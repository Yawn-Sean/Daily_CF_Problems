n = II()
a = LII()
b = LII()
c = LII()

f = [[0, 0, 0, 0] for _ in range(n)]
f[0] = [a[0], 0, b[0], 0]

for i in range(1, n):
    f[i][0] = fmax(f[i - 1][2], f[i - 1][3]) + a[i]
    f[i][1] = fmax(f[i - 1][0], f[i - 1][1]) + b[i]
    f[i][2] = fmax(f[i - 1][2], f[i - 1][3]) + b[i]
    f[i][3] = fmax(f[i - 1][0], f[i - 1][1]) + c[i]

print(fmax(f[n - 1][0], f[n - 1][1]))
