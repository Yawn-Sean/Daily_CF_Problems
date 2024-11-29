y = "aeiouAEIOU"
s = I()

n = len(s)
f = [-1] * n

for i in range(n):
    if not s[i] in y:
        f[i] = 2

pre = list(accumulate(f, initial=0))

mx_idx = defaultdict(int)
for i in range(n + 1):
    mx_idx[pre[i]] = i

mi_idx = defaultdict(int)
for i in range(n, -1, -1):
    mi_idx[pre[i]] = i

ans = 0
mi = n
for x in sorted(mx_idx.keys()):
    mi = fmin(mi, mi_idx[x])
    ans = fmax(ans, mx_idx[x] - mi)

tmp = 0
for i in range(n - ans + 1):
    if pre[i + ans] - pre[i] >= 0:
        tmp += 1
if ans:
    print(ans, tmp)
else:
    print("No solution")
