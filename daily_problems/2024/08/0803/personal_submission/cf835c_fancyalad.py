# submission link: https://codeforces.com/problemset/submission/835/274247095

import sys

input = lambda: sys.stdin.readline().strip()

def solve():
    dp = [[0] * (101 * 101) for _ in range(11)]

    def f (x: int, y: int) -> int:
        return x * 101 + y

    n, q, c = map(int, input().split())
    for i in range(n):
        x, y, s = map(int, input().split())
        for i in range(c + 1):
            dp[i][f(x, y)] += (s + i) % (c + 1)
        
    for i in range(c + 1):
        for x in range(101):
            for y in range(100):
                dp[i][f(x, y + 1)] += dp[i][f(x, y)]
        
        for y in range(101):
            for x in range(100):
                dp[i][f(x + 1, y)] += dp[i][f(x, y)]
        
    outs = []
    for i in range(q):
        t, x1, y1, x2, y2 = map(int, input().split())
        outs.append(dp[t % (c + 1)][f(x2, y2)] - dp[t % (c + 1)][f(x1 - 1, y2)] - \
                    dp[t % (c + 1)][f(x2, y1 - 1)] + dp[t % (c + 1)][f(x1 - 1, y1 - 1)])

    print('\n'.join(map(str, outs)))
solve()