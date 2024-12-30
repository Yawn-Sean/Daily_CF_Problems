# Submission link: https://codeforces.com/contest/1056/submission/261442112
def main():
    n, m = MII()
    s1 = I()
    s2 = I()

    transition0 = [0] * (m + 1)
    transition1 = [0] * (m + 1)

    for i in range(m + 1):
        # prep(x, y) 处理 x 前缀和 y 后缀的最大匹配
        transition0[i] = prep(s2, s2[:i] + '0')
        transition1[i] = prep(s2, s2[:i] + '1')

    def f(x, y):
        return x * (m + 1) + y

    k = (m + 1) * (n - m + 2)
    dp = [[n + 1] * k for _ in range(2)]

    dp[0][f(0, 0)] = 0

    for i in range(n):
        c = int(s1[i])
        i = i % 2
        ni = i ^ 1
        
        for j in range(k):
            dp[ni][j] = n + 1
        
        for cnt in range(n - m + 1):
            for cur in range(m + 1):
                if dp[i][f(cnt, cur)] < n:
                    # new digit is 0
                    ncnt = cnt
                    ncur = transition0[cur]
                    if ncur == m: ncnt += 1
                    dp[ni][f(ncnt, ncur)] = min(dp[ni][f(ncnt, ncur)], dp[i][f(cnt, cur)] + c)
                    # new digit is 1
                    ncnt = cnt
                    ncur = transition1[cur]
                    if ncur == m: ncnt += 1
                    dp[ni][f(ncnt, ncur)] = min(dp[ni][f(ncnt, ncur)], dp[i][f(cnt, cur)] + (c ^ 1))

    ans = [n + 1] * (n - m + 2)
    for cnt in range(n - m + 2):
        for cur in range(m + 1):
            ans[cnt] = min(ans[cnt], dp[ni][f(cnt, cur)])

    print(' '.join(str(x) if x <= n else '-1' for x in ans))