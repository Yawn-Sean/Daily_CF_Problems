# Submission link: https://codeforces.com/contest/900/submission/283112597
def main():
    n = II()
    s = I()
    m = II()

    check_a = [0] * (n + 1)
    check_b = [0] * (n + 1)
    cnt_q = [0] * (n + 1)

    for i in range(n):
        cnt_q[i + 1] = cnt_q[i]
        if s[i] == '?':
            cnt_q[i + 1] += 1

    for i in range(n - 1, -1, -1):
        check_a[i] = check_b[i + 1] + 1 if s[i] != 'b' else 0
        check_b[i] = check_a[i + 1] + 1 if s[i] != 'a' else 0

    dp = [0] * (n + 1)
    change = [0] * (n + 1)

    for i in range(n):
        if dp[i] > dp[i + 1] or (dp[i] == dp[i + 1] and change[i] < change[i + 1]):
            dp[i + 1] = dp[i]
            change[i + 1] = change[i]
        
        if check_a[i] >= m:
            nv = dp[i] + 1
            nc = change[i] + cnt_q[i + m] - cnt_q[i]
            
            if nv > dp[i + m] or (nv == dp[i + m] and nc < change[i + m]):
                dp[i + m] = nv
                change[i + m] = nc

    print(change[n])