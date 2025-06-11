mii = lambda: map(int, input().split())
fmin = lambda a, b: a if a < b else b

n, l, k = mii()
prob = [x*0.01 for x in mii()]
bag = list(mii())
maxcap = l + bag.count(-1)
pairs = sorted(zip(bag, prob), reverse=True)

dp = [[0.] * (maxcap+1) for _ in range(n+1)]
dp[0][fmin(k, maxcap)] = 1.
for idx, (b, p) in enumerate(pairs):
    tmp = [[0.] * (maxcap+1) for _ in range(n+1)]
    for win in range(idx+1):
        for cap in range(0 if b > 0 else 1, maxcap+1):
            tmp[win+1][fmin(maxcap, cap+b)] += dp[win][cap] * p
        for cap in range(maxcap+1):
            tmp[win][cap] += dp[win][cap] * (1-p)
    dp = tmp

ans = sum(sum(dp[i]) for i in range(l, n+1))
print(ans)