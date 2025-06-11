# Submission link: https://codeforces.com/contest/494/submission/279731582
def main():
    s1 = I()
    s2 = I()

    n = len(s1)
    k = len(s2)
    kmp = prep(s2 + '$' + s1)[k + 1:]

    prev = [-1] * n
    for i in range(n):
        if kmp[i] == k: prev[i] = i
        elif i: prev[i] = prev[i-1]

    mod = 10 ** 9 + 7
    dp = [0] * n
    dp_acc = [0] * n
    dp_pref = [0] * n

    for i in range(n):
        if prev[i] != -1:
            dp[i] = prev[i] - k + 2
            if prev[i] >= k :
                dp[i] += dp_pref[prev[i]-k]
                dp[i] %= mod
        if i:
            dp_acc[i] = dp_acc[i-1]
            dp_pref[i] = dp_pref[i-1]
        dp_acc[i] += dp[i]
        dp_acc[i] %= mod
        dp_pref[i] += dp_acc[i]
        dp_pref[i] %= mod

    print(dp_acc[-1])