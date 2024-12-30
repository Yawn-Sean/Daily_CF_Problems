'''
https://codeforces.com/contest/1196/submission/268014181
1196/D2
2024/6/29 Y1
1600
DP: dp[i][0/1/2] 表示 前i+1个字符前缀中保持队形，并且最后一个字母为R/G/B时的最小删除数量
'''

def init():
    n, k = map(int, input().split())
    s = input()
    return n, k, s

def solve(n, k, s):
    if k == 1: return 0
    ans = n + 1
    dp = [[0, 0, 0] for _ in range(n)]
    for i, c in enumerate(s):
        dp[i][:] = (0 if c == 'R' else 1, 0 if c == 'G' else 1, 0 if c == 'B' else 1)
        if i > 0:
            dp[i][0] += dp[i - 1][2]
            dp[i][1] += dp[i - 1][0]
            dp[i][2] += dp[i - 1][1]
        if i == k - 1:
            ans = min(dp[i])
        elif i >= k:
            d0 = dp[i][0] - dp[i - k][-(k % 3) % 3]
            d1 = dp[i][1] - dp[i - k][(1 - k % 3) % 3]
            d2 = dp[i][2] - dp[i - k][(2 - k % 3) % 3]
            ans = min(ans, d0, d1, d2)
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
