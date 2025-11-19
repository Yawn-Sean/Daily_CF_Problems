import sys
input = lambda: sys.stdin.readline().rstrip()

mod = 998244353

def soviet():
    n = int(input())
    a = [0] + sorted(list(map(int, input().split())))

    dp = [[0] * (n + 1) for _ in range(n + 2)]
    dp_sum = [[0] * (n + 1) for _ in range(n + 2)]

    for i in range(1, n + 1):
        idx = 1
        for j in range(i + 1, n + 1):
            while idx < i and a[idx] + a[i] <= a[j]:
                idx += 1
            dp[i][j] = (dp_sum[idx - 1][i] + 1) % mod
            dp_sum[i][j] = (dp_sum[i - 1][j] + dp[i][j]) % mod

    ans = n
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            ans = (ans + dp[i][j]) % mod

    print(ans)

soviet()
