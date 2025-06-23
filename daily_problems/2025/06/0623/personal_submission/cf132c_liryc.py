'''
https://codeforces.com/problemset/submission/132/325688363
'''
# (OTK) DP: dp[i][k][status] = maxlength
# status = { F, T, -F, -T }
pmax = lambda x, y: y if y > x else x

def init():
    commands = input()
    n = int(input())
    return commands, n

def solve1(commands: str, n: int) -> int:
    n, k = len(commands), n
    dp = [[-1024] * 4 for _ in range(n)]
    if commands[0] == 'F':
        dp[0][0] = 1
    else:
        dp[0][3] = 0
    for i in range(1, n):
        if commands[i] == 'F':
            if dp[i - 1][0] > -101 or dp[i - 1][1] > -101:
                dp[i][0] = pmax(dp[i - 1][0] + 1, dp[i - 1][1] + 1)
            if dp[i - 1][2] > -101 or dp[i - 1][3] > -101:
                dp[i][2] = pmax(dp[i - 1][2] - 1, dp[i - 1][3] - 1)
        else:
            if dp[i - 1][0] > -101 or dp[i - 1][1] > -101:
                dp[i][3] = pmax(dp[i - 1][0], dp[i - 1][1])
            if dp[i - 1][2] > -101 or dp[i - 1][3] > -101:
                dp[i][1] = pmax(dp[i - 1][2], dp[i - 1][3])
    for _ in range(k):
        dp1 = [[-1024] * 4 for _ in range(n)]
        if dp[0][3] > -101:
            dp1[0][0] = dp[0][3] + 1
        if dp[0][2] > -101:
            dp1[0][1] = dp[0][2] + 1
        if dp[0][1] > -101:
            dp1[0][2] = dp[0][1] - 1
        if dp[0][0] > -101:
            dp1[0][3] = dp[0][0] - 1
        for i in range(1, n):
            if commands[i] == 'F' and (dp1[i - 1][0] > -101 or dp1[i - 1][1] > -101):
                dp1[i][0] = pmax(dp1[i - 1][0] + 1, dp1[i - 1][1] + 1)
            if dp[i][3] > -101:
                dp1[i][0] = pmax(dp1[i][0], dp[i][3] + 1)
            if commands[i] == 'T' and (dp1[i - 1][2] > -101 or dp1[i - 1][3] > -101):
                dp1[i][1] = pmax(dp1[i - 1][2], dp1[i - 1][3])
            if dp[i][2] > -101:
                dp1[i][1] = pmax(dp1[i][1], dp[i][2] + 1)
            if commands[i] == 'F' and (dp1[i - 1][2] > -101 or dp1[i - 1][3] > -101):
                dp1[i][2] = pmax(dp1[i - 1][2] - 1, dp1[i - 1][3] - 1)
            if dp[i][1] > -101:
                dp1[i][2] = pmax(dp1[i][2], dp[i][1] - 1)
            if commands[i] == 'T' and (dp1[i - 1][0] > -101 or dp1[i - 1][1] > -101):
                dp1[i][3] = pmax(dp1[i - 1][0], dp1[i - 1][1])
            if dp[i][0] > -101:
                dp1[i][3] = pmax(dp1[i][3], dp[i][0] - 1)
        dp = dp1
    return max(dp[-1])

def solve2(commands: str, n: int) -> int:
    n, k = len(commands), n
    dp = [[-1024] * 4 for _ in range(n)]
    if commands[0] == 'F':
        dp[0][2] = -1
    else:
        dp[0][1] = 0
    for i in range(1, n):
        if commands[i] == 'F':
            if dp[i - 1][0] > -101 or dp[i - 1][1] > -101:
                dp[i][0] = pmax(dp[i - 1][0] + 1, dp[i - 1][1] + 1)
            if dp[i - 1][2] > -101 or dp[i - 1][3] > -101:
                dp[i][2] = pmax(dp[i - 1][2] - 1, dp[i - 1][3] - 1)
        else:
            if dp[i - 1][0] > -101 or dp[i - 1][1] > -101:
                dp[i][3] = pmax(dp[i - 1][0], dp[i - 1][1])
            if dp[i - 1][2] > -101 or dp[i - 1][3] > -101:
                dp[i][1] = pmax(dp[i - 1][2], dp[i - 1][3])
    for _ in range(k):
        dp1 = [[-1024] * 4 for _ in range(n)]
        if dp[0][3] > -101:
            dp1[0][0] = dp[0][3] + 1
        if dp[0][2] > -101:
            dp1[0][1] = dp[0][2] + 1
        if dp[0][1] > -101:
            dp1[0][2] = dp[0][1] - 1
        if dp[0][0] > -101:
            dp1[0][3] = dp[0][0] - 1
        for i in range(1, n):
            if commands[i] == 'F' and (dp1[i - 1][0] > -101 or dp1[i - 1][1] > -101):
                dp1[i][0] = pmax(dp1[i - 1][0] + 1, dp1[i - 1][1] + 1)
            if dp[i][3] > -101:
                dp1[i][0] = pmax(dp1[i][0], dp[i][3] + 1)
            if commands[i] == 'T' and (dp1[i - 1][2] > -101 or dp1[i - 1][3] > -101):
                dp1[i][1] = pmax(dp1[i - 1][2], dp1[i - 1][3])
            if dp[i][2] > -101:
                dp1[i][1] = pmax(dp1[i][1], dp[i][2] + 1)
            if commands[i] == 'F' and (dp1[i - 1][2] > -101 or dp1[i - 1][3] > -101):
                dp1[i][2] = pmax(dp1[i - 1][2] - 1, dp1[i - 1][3] - 1)
            if dp[i][1] > -101:
                dp1[i][2] = pmax(dp1[i][2], dp[i][1] - 1)
            if commands[i] == 'T' and (dp1[i - 1][0] > -101 or dp1[i - 1][1] > -101):
                dp1[i][3] = pmax(dp1[i - 1][0], dp1[i - 1][1])
            if dp[i][0] > -101:
                dp1[i][3] = pmax(dp1[i][3], dp[i][0] - 1)
        dp = dp1
    return max(dp[-1])

if __name__ == '__main__':
    args = init()
    ans = pmax(solve1(*args), solve2(*args))
    print(ans)
