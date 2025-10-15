'''
https://codeforces.com/problemset/submission/930/312788581
'''
# probabilities
def solve(s: str) -> float:
    n = len(s)
    dq = deque(ord(c) - 97 for c in s)
    dp = [[[0] * 26 for _ in range(n - 1)] for _ in range(26)]
    cn = [0] * 26
    for _ in range(n):
        dq.rotate()
        x = dq[0]
        cn[x] += 1
        for i in range(n - 1):
            c = dq[i + 1]
            dp[x][i][c] += 1
    ans = 0.0
    for x in range(26):
        if cn[x]:
            ans += max(sum(c == 1 for c in r) for r in dp[x])
    return ans / n