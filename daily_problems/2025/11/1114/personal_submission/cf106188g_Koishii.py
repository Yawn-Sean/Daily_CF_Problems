import sys
input = lambda: sys.stdin.readline().rstrip()

mod = 10**9 + 7

def soviet():
    n, k = map(int, input().split())
    m = 0
    a = [9] + list(map(int, input().split()))
    m = max(a[1:])
    a[1:] = sorted(a[1:])

    dp = [[0] * k for _ in range(m + 2)]
    dp[0][0] = 1


    ans = 0
    for i in range(1, n + 1):
        for j in range(a[i] + 1, m + 2):
            ans = (ans + dp[j][k - 1]) % mod
        for j in range(m + 1, -1, -1):
            nj = min(j + a[i], m + 1)
            for z in range(k - 2, -1, -1):
                nz = z + 1
                dp[nj][nz] = (dp[nj][nz] + dp[j][z]) % mod

    print(ans)

soviet()
