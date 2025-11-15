fmax = lambda x, y: x if x > y else y

n = ix()
a = il()
dp = [[0] * n for i in range(n)]
for x in range(1, n):
    for l in range(n - x):
        r = l + x
        dp[l][r] = dp[l + 1][r - 1]
        if a[l] % a[r] == 0 or a[r] % a[l] == 0:
            dp[l][r] += 2
        for s in range(l , r):
            dp[l][r] = fmax(dp[l][r], dp[l][s] + dp[s + 1][r])
res = [0] * n

def check(l, r):
    if l >= r: return
    for s in range(l, r):
        if dp[l][r] == dp[l][s] + dp[s + 1][r]:
            check(l, s)
            check(s + 1, r)
            return
    if a[l] % a[r] == 0 or a[r] % a[l] == 0:
        res[l] = 1
        res[r] = 1
    check(l + 1, r - 1)

check(0, n - 1)
print(n - dp[0][n - 1])
print(*(i + 1 for i in range(n) if not res[i]))
