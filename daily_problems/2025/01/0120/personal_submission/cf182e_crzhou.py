n, tot = MII()
arr = []
brr = []

for _ in range(n):
    a, b = MII()
    arr.append(a)
    brr.append(b)

f = [[[0 for _ in range(2)] for _ in range(n + 1)] for _ in range(tot + 1)]
for i in range(n):
    a, b = arr[i], brr[i]
    if a <= tot:
        f[a][i][0] += 1
    if a != b:
        if b <= tot:
            f[b][i][1] += 1

for cur in range(1, tot + 1):
    for i in range(n):
        prea, preb = arr[i], brr[i]
        for j in range(n):
            if j != i:
                cura, curb = arr[j], brr[j]
                if cura == preb:
                    if cur + cura <= tot:
                        f[cur + cura][j][0] = (f[cur + cura][j][0] + f[cur][i][0]) % MOD
                if cura != curb and curb == preb:
                    if cur + curb <= tot:
                        f[cur + curb][j][1] = (f[cur][i][0] + f[cur + curb][j][1]) % MOD
        if prea != preb:
            for j in range(n):
                if j != i:
                    cura, curb = arr[j], brr[j]
                    if cura == prea:
                        if cur + cura <= tot:
                            f[cur + cura][j][0] = (f[cur][i][1] + f[cur + cura][j][0]) % MOD
                    if cura != curb and curb == prea:
                        if cur + curb <= tot:
                            f[cur + curb][j][1] = (f[cur][i][1] + f[cur + curb][j][1]) % MOD
                    
ans = 0
for i in range(n):
    ans = (ans + f[tot][i][0] + f[tot][i][1]) % MOD

print(ans)
