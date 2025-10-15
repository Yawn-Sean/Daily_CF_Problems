# Submission link: https://codeforces.com/contest/1340/submission/309142364
def main():
    digits = [119, 18, 93, 91, 58, 107, 111, 82, 127, 123]

    n, k = MII()
    strs = [int(I(), 2) for _ in range(n)]

    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[n][0] = 1

    for i in range(n - 1, -1, -1):
        for j in range(k + 1):
            if dp[i + 1][j]:
                for digit in range(10):
                    if digits[digit] & strs[i] == strs[i]:
                        nj = (digits[digit] ^ strs[i]).bit_count()
                        if j + nj <= k:
                            dp[i][j + nj] = 1

    if dp[0][k] == 0: print(-1)
    else:
        ans = []
        cur = k
        
        for i in range(n):
            for digit in range(9, -1, -1):
                if digits[digit] & strs[i] == strs[i]:
                    nj = (digits[digit] ^ strs[i]).bit_count()
                    if cur >= nj and dp[i + 1][cur - nj]:
                        cur -= nj
                        ans.append(digit)
                        break
        
        print(*ans, sep='')