# Submission link: https://codeforces.com/contest/1025/submission/261262173
def main():
    s = I()
    n = len(s)
    s = s * 2

    ans = 0
    cnt = 1
    for i in range(2 * n - 1):
        if s[i] != s[i+1]: cnt += 1
        else: cnt = 1
        ans = max(ans, cnt)

    print(min(ans, n))