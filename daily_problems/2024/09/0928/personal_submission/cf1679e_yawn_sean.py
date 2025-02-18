# Submission link: https://codeforces.com/contest/1679/submission/283293072
def main():
    n = II()
    s = I()

    ques = [0] * (n + 1)
    for i in range(n):
        ques[i + 1] = ques[i]
        if s[i] == '?':
            ques[i + 1] += 1

    mod = 998244353

    pows = [[1] * (n + 1) for _ in range(18)]
    for i in range(1, 18):
        for j in range(n):
            pows[i][j + 1] = pows[i][j] * i % mod

    dp = [[0] * n for _ in range(n)]
    cnt = [[0] * n for _ in range(n)]

    for l in range(n - 1, -1, -1):
        if s[l] == '?':
            cnt[l][l] = 1
        
        for r in range(l + 1, n):
            if dp[l + 1][r - 1] == -1 or (s[l] != '?' and s[r] != '?' and s[l] != s[r]):
                dp[l][r] = -1
            else:
                dp[l][r] = dp[l + 1][r - 1]
                cnt[l][r] = cnt[l + 1][r - 1]
                
                if s[l] != '?' and s[r] == '?':
                    dp[l][r] |= 1 << ord(s[l]) - ord('a')
                elif s[l] == '?' and s[r] != '?':
                    dp[l][r] |= 1 << ord(s[r]) - ord('a')
                elif s[l] == '?' and s[r] == '?':
                    cnt[l][r] += 1

    calc = [[0] * (1 << 17) for _ in range(18)]

    for l in range(n):
        for r in range(l, n):
            if dp[l][r] != -1:
                for i in range(1, 18):
                    calc[i][dp[l][r]] += pows[i][cnt[l][r] + ques[l] + ques[n] - ques[r + 1]]
                    calc[i][dp[l][r]] %= mod

    for i in range(1, 18):
        for j in range(18):
            for msk in range(1 << 17):
                if msk >> j & 1:
                    calc[i][msk] += calc[i][msk - (1 << j)]
                    calc[i][msk] %= mod

    q = II()
    outs = []
    for _ in range(q):
        s = I()
        msk = 0
        for c in s:
            msk |= 1 << ord(c) - ord('a')
        outs.append(calc[msk.bit_count()][msk])

    print('\n'.join(map(str, outs)))