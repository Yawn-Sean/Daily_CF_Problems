# Submission link: https://codeforces.com/contest/645/submission/288013157
def main():
    n, k = MII()
    s = [ord(c) - ord('a') for c in I()]

    m = len(s)
    last = [-1] * k
    for i in range(m):
        last[s[i]] = i

    order = sorted(range(k), key=lambda x: last[x])

    dp = [0] * k
    total = 0
    mod = 10 ** 9 + 7

    for c in s:
        v = total - dp[c] + 1
        if v < 0: v += mod
        dp[c] += v
        if dp[c] >= mod: dp[c] -= mod
        total += v
        if total >= mod: total -= mod

    for i in range(n):
        c = order[i % k]
        v = total - dp[c] + 1
        if v < 0: v += mod
        dp[c] += v
        if dp[c] >= mod: dp[c] -= mod
        total += v
        if total >= mod: total -= mod

    total += 1
    if total == mod:
        total = 0
    print(total)