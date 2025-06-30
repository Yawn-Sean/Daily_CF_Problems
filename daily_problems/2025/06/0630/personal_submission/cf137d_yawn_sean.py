# Submission link: https://codeforces.com/contest/137/submission/326590308
def main():
    s = [ord(c) for c in I()]
    k = II()

    n = len(s)

    change = [[0] * n for _ in range(n)]

    for diff in range(1, n):
        for l in range(n - diff):
            r = l + diff
            change[l][r] = change[l + 1][r - 1] + (s[l] != s[r])

    dp = [[n + 1] * n for _ in range(k)]
    pre = [[-1] * n for _ in range(k)]

    for i in range(n):
        dp[0][i] = change[0][i]

    for i in range(k - 1):
        for j in range(n - 1):
            for nj in range(j + 1, n):
                if dp[i][j] + change[j + 1][nj] < dp[i + 1][nj]:
                    dp[i + 1][nj] = dp[i][j] + change[j + 1][nj]
                    pre[i + 1][nj] = j

    v = n + 1
    chosen = -1

    for i in range(k):
        if dp[i][n - 1] < v:
            v = dp[i][n - 1]
            chosen = i

    ans = []

    cur = n - 1
    for i in range(chosen, -1, -1):
        ncur = pre[i][cur]
        
        l, r = ncur + 1, cur
        while l < r:
            s[l] = s[r]
            l += 1
            r -= 1
        
        ans.append(''.join(chr(s[x]) for x in range(ncur + 1, cur + 1)))
        
        cur = ncur

    ans.reverse()

    print(v)
    print('+'.join(ans))