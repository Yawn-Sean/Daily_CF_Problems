def solve():
    s = input()
    n = len(s)

    cnt = [0] * 26
    for ch in s:
        cnt[ord(ch)-97] += 1
    idx = max(range(26), key=cnt.__getitem__)
    if cnt[idx] >= 100:
        return chr(idx+97) * 100

    dp = [[0] * n for _ in range(n)]
    for l in range(n-1, -1, -1):
        dp[l][l] = 1
        for r in range(l+1, n):
            if s[l] == s[r]:
                dp[l][r] = dp[l+1][r-1] + 2
            else:
                dp[l][r] = max(dp[l+1][r], dp[l][r-1])

    l, r = 0, n-1
    indices = []
    while l < r:
        if s[l] == s[r]:
            indices.append(l)
            l += 1
            r -= 1
        else:
            if dp[l+1][r] > dp[l][r-1]:
                l += 1
            else:
                r -= 1

    half = ''.join(s[i] for i in indices)
    if len(half) >= 50:
        half = half[:50]
        return half + half[::-1]
    if len(half) * 2 != dp[0][n-1]:
        return half + s[l] + half[::-1]
    else:
        return half + half[::-1]

print(solve())