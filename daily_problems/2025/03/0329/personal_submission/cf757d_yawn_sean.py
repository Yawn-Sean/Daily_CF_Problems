# Submission link: https://codeforces.com/problemset/submission/757/312871611
def main():
    n = II()
    s = [int(c) for c in I()]

    total = 1 << 20

    dp = [[0] * total for _ in range(11)]
    dp_sep = [0] * total

    ans = 0
    mod = 10 ** 9 + 7

    possible = [0] * 11
    npossible = [0] * 11

    possible[0] = 1

    for i in range(n):
        dp[0][0] += 1
        if dp[0][0] >= mod:
            dp[0][0] -= mod
        
        possible[0] = 1
        
        for x in range(11):
            if not possible[x]: continue
            
            for y in range(total):
                if dp[x][y] and 1 <= x * 2 + s[i] <= 20:
                    ny = y | (1 << (x * 2 + s[i] - 1))
                    dp_sep[ny] += dp[x][y]
                    if dp_sep[ny] >= mod:
                        dp_sep[ny] -= mod

        for x in range(1, 20):
            ans += dp_sep[(1 << x) - 1]
            if ans >= mod: ans -= mod
        
        for x in range(10, -1, -1):
            if possible[x]:
                if 2 * x + s[i] <= 10:
                    npossible[2 * x + s[i]] = 1
                    for y in range(total):
                        dp[2 * x + s[i]][y] = dp[x][y]
                if x + s[i]:
                    for y in range(total):
                        dp[x][y] = 0
        
        for x in range(total):
            dp[0][x] += dp_sep[x]
            if dp[0][x] >= mod:
                dp[0][x] -= mod
            dp_sep[x] = 0
        
        for x in range(11):
            possible[x] = npossible[x]
            npossible[x] = 0

    print(ans)