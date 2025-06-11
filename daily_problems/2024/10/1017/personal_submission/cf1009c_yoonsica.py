# https://codeforces.com/contest/1009/submission/286308110
# 每个元素都要+n*x，主要看d*abs(i - j)如何分配，d<0,则应该让sum(abs(i - j)最小，反之最大
# 最小放中间，最大放两边
n, m = RII()
ans = 0
for _ in range(m):
    x, d = RII()
    ans += n * x
    if d < 0:
        # i取中间
        if n & 1:
            # 1 + 2 + ... + n // 2
            cnt = n // 2
            ans += (1 + cnt) * cnt * d
        else:
            cnt = (n - 1) // 2
            ans += (1 + cnt) * cnt * d + n * d // 2
    else:
        # i取两边
        ans += n * (n - 1) * d // 2
print(ans / n)
