def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/1561/D1
    submission: https://codeforces.com/contest/1561/submission/264358989
    """
    n, m = ac.read_list_ints()
    dp = [0] * (n + 1)
    s  = 0 # 后缀和 
    dp[n] = 1 
    for i in range(n, 1, -1):
        # 更新方法1的方案数
        dp[i] += s 
        # 更新方法2的方案数
        dp[1] = (dp[1] + (i + 1) // 2 * dp[i] % m) % m
        for j in range(2, i):
            if j ** 2 > i: break 
            cur = i // j 
            dp[cur] = (dp[cur] + dp[i]) % m
            if cur != j: 
                nxt = i // (j + 1)
                dp[j] = (dp[j] + dp[i] * (cur - nxt) % m) % m 
        s += dp[i]
        s %= m 
    ac.st((dp[1] + s) % m)
