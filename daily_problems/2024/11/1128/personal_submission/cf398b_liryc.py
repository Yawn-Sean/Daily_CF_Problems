'''
https://codeforces.com/problemset/submission/398/293663496
398B
2024/11/28 Y1
1700
probability DP
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    rs, cs = set(), set()
    for _ in range(m):
        r, c = map(int, input().split())
        rs.add(r)
        cs.add(c)
    return n, n - len(rs), n - len(cs)

def solve(n: int, r: int, c: int):
    dp = [[0] * (c + 2) for _ in range(r + 2)]

    for i in range(r, -1, -1):
        for j in range(c, -1, -1):
            if i == r and j == c: continue
            dp[i][j] = (n * n + (r - i) * (c - j) * dp[i + 1][j + 1]
                        + (r - i) * (n - c + j) * dp[i + 1][j]
                        + (n - r + i) * (c - j) * dp[i][j + 1]) / (n * n - (n - r + i) * (n - c + j))
    return dp[0][0]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
