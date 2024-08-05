'''
https://codeforces.com/contest/835/submission/274105086
835C
2024/8/3 Y1
1600
DP, prefix sum
'''

def solve() -> list[int]:
    n, q, c = map(int, input().split())
    c += 1
    dp = [[[0] * 101 for _ in range(c)] for _ in range(101)]
    for _ in range(n):
        x, y, s = map(int, input().split())
        for t in range(c):
            dp[x][t][y] += (s + t) % c
    for x in range(1, 101):
        for t in range(c):
            for y in range(2, 101):
                dp[x][t][y] += dp[x][t][y - 1]
            for y in range(1, 101):
                dp[x][t][y] += dp[x - 1][t][y]
    ans = [0] * q
    for i in range(q):
        t, x1, y1, x2, y2 = map(int, input().split())
        t %= c
        ans[i] = (dp[x2][t][y2] - dp[x2][t][y1 - 1]) - (dp[x1 - 1][t][y2] - dp[x1 - 1][t][y1 - 1])
    return ans

if __name__ == '__main__':
    ans = solve()
    print(*ans, sep = '\n')
