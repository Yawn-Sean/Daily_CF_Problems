# Submission link: https://codeforces.com/problemset/submission/73/321567002
def main():
    s, k = LI()

    s = [ord(c) - ord('a') for c in s]
    k = int(k)

    grid = [[0] * 26 for _ in range(26)]

    n = II()
    for _ in range(n):
        c1, c2, v = LI()
        grid[ord(c1) - ord('a')][ord(c2) - ord('a')] = int(v)

    inf = 10 ** 9
    dp = [[-inf] * 26 for _ in range(k + 1)]
    ndp = [[-inf] * 26 for _ in range(k + 1)]

    for i in range(26):
        if s[0] == i: dp[0][i] = 0
        elif k: dp[1][i] = 0

    for i in range(1, len(s)):
        for x in range(k + 1):
            for y in range(26):
                for ny in range(26):
                    nx = x + 1 if ny != s[i] else x
                    if nx <= k:
                        ndp[nx][ny] = fmax(ndp[nx][ny], dp[x][y] + grid[y][ny])
        
        for x in range(k + 1):
            for y in range(26):
                dp[x][y] = ndp[x][y]
                ndp[x][y] = -inf

    print(max(max(v) for v in dp))