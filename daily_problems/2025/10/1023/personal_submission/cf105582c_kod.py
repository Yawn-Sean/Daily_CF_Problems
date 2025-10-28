n, mmin, mmax = il()
m, c = [], []
for x in range(n):
    a, b = il()
    m += a,
    c += b,

l, r = 1, 10 ** 6

while l <= r:
    mid = (l + r) >> 1
    dp = [1] + [0] * (10 ** 4)
    for i in range(n):
        mm = m[i]
        cc = c[i] // mid
        for j in range(mm):
            b = -1
            for k in range(j, 10 ** 4 + 1, mm):
                if dp[k]:
                    b = max(b, k + cc * mm)
                if k <= b:
                    dp[k] = 1
    if any(x for x in dp[mmin: mmax + 1]):
        l = mid + 1
    else:
        r = mid - 1
print(r)
