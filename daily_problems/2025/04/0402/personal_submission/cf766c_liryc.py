'''
https://codeforces.com/problemset/submission/766/313575417
'''
# DP+SlidingWindow+DP (一发盲交AC ^_^)
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x

def solve1(n: int, s: str, a: list[int]) -> int:
    MOD = 1000000007
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        k = i + 1
        r = n
        for m in range(1, k + 1):
            x = ord(s[i - m + 1]) - 97
            r = pmin(r, a[x])
            if m > r:
                break
            else:
                dp[k] += dp[k - m]
        dp[k] %= MOD
    return dp[-1]

def solve2(n: int, s: str, a: list[int]) -> int:
    i = 0
    cn = [0] * 26
    hp = []
    ans = 0
    for j, c in enumerate(s):
        x = ord(c) - 97
        cn[x] += 1
        if cn[x] == 1:
            heappush(hp, (a[x], x))
        while j - i + 1 > hp[0][0]:
            y = ord(s[i]) - 97
            i += 1
            cn[y] -= 1
            while cn[hp[0][1]] == 0:
                heappop(hp)
        ans = pmax(ans, j - i + 1)
    return ans

def solve3(n: int, s: str, a: list[int]) -> int:
    dp = list(range(1, n + 1))
    for i in range(n):
        k = i + 1
        r = n
        for m in range(1, k + 1):
            x = ord(s[i - m + 1]) - 97
            r = pmin(r, a[x])
            if m > r:
                break
            else:
                if m == k:
                    dp[i] = 1
                else:
                    dp[i] = pmin(dp[i], dp[i - m] + 1)
    return dp[-1]
