n = int(input())
a = [''] * (n + 1)
for i in range(1, n + 1):
    a[i] = ' ' + input().strip()

ans = 0
row = [0] * (n + 1)
col = [0] * (n + 1) 

for i in range(n, 0, -1):
    for j in range(1, i):
        if int(a[i][j]) != (row[i] ^ col[j]):
            ans += 1
            row[i] ^= 1
            col[j] ^= 1

row1 = [0] * (n + 1)
col1 = [0] * (n + 1)

for i in range(1, n + 1):
    for j in range(n, i, -1):
        if int(a[i][j]) != (row1[i] ^ col1[j]):
            ans += 1
            row1[i] ^= 1
            col1[j] ^= 1

for i in range(1, n + 1):
    if int(a[i][i]) != (row[i] ^ col[i] ^ row1[i] ^ col1[i]):
        ans += 1

print(ans)
