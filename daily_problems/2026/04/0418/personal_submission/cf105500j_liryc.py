'''
20260418 Y2 2300
'''
def solve(n: int, k: int) -> int:
    MOD = 1000000007
    ans = 0
    d0, d1 = [0] * (n + 1), [0] * (n + 1)
    d0[0] = 1
    for i in range(k):
        for j in range(n + 1):
            d1[j] = 0
        for j in range(n + 1):
            if i and i + j <= n:
                d0[i + j] += d0[j]
                d0[i + j] %= MOD
            if i + 1 <= n and j + 1 <= n:
                d1[j + 1] += d0[j]
                d1[j + 1] %= MOD
        y = k - i
        for x in range(1, n // y + 1):
            ans += x * x * d0[n - y * x] % MOD
            ans %= MOD
        d0, d1 = d1, d0
    return ans