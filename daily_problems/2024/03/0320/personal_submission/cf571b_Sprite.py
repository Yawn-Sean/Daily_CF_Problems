from itertools import accumulate
n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
cnt = n // k
if not n % k:
    ans = 0
    for i in range(cnt-1, n, cnt):
        ans += a[i] - a[i-cnt+1]
    print(ans)
else:
    more = n % k
    dp = [0] * (k+1)
    for i in range(1, k+1):
        dp[i] = dp[i-1] + a[cnt*i-1] - a[cnt*(i-1)]
    for j in range(1, more+1):
        dp_new = [0] * (k+1)
        dp_new[j] = dp[j-1] + a[cnt*j+j-1] - a[(cnt+1)*(j-1)]
        for i in range(j+1, k+1):
            dp_new[i] = min(dp_new[i-1] + a[cnt*i+j-1] - a[cnt*(i-1)+j], dp[i-1] + a[cnt*i+j-1] - a[cnt*(i-1)+j-1])
        dp = dp_new
    print(dp[-1])
