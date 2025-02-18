# Submission link: https://codeforces.com/contest/803/submission/283967196
def main():
    n, k = MII()
    s = I()

    dp = [[-2] * (2 * k + 1) for _ in range(n + 1)]
    dp[0][k] = 0

    d = {
        'L': [-1],
        'D': [0],
        'W': [1],
        '?': [-1, 0, 1]
    }

    for i in range(n):
        for dj in d[s[i]]:
            for j in range(1, 2 * k):
                if dp[i][j] != -2:
                    dp[i + 1][j + dj] = dj

    if dp[n][0] != -2:
        cur = 0
    elif dp[n][2 * k] != -2:
        cur = 2 * k
    else:
        exit(print('NO'))

    status = {
        -1: 'L',
        0: 'D',
        1: 'W'
    }

    ans = []
    for i in range(n, 0, -1):
        ans.append(status[dp[i][cur]])
        cur -= dp[i][cur]

    ans.reverse()
    print(''.join(ans))