n = II()
s = I()

cntg = 0
for c in s:
    if c == 'G':
        cntg += 1

f = [0] * n
if s[0] == 'G':
    f[0] = 1

for i in range(1, n):
    if s[i] == 'G':
        f[i] = f[i-1] + 1

tmp = []
for i in range(n):
    if s[i] == 'S' and i:
        tmp.append(f[i - 1])
    if s[i] == 'S':
        tmp.append(0)
if f[-1]:
    tmp.append(f[-1])

ans = 0
for i, c in enumerate(tmp):
    if c == 0:
        cur = 0
        if i:
            cur += tmp[i - 1]
        if i < len(tmp) - 1:
            cur += tmp[i + 1]
        ans = fmax(ans, cur + 1)
    else:
        ans = fmax(ans, tmp[i])
    
print(fmin(ans, cntg))
