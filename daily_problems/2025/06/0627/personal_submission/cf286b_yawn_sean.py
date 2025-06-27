# Submission link: https://codeforces.com/problemset/submission/286/326210097
def main():
    n = II()
    ans = [0] * (2 * n)

    for i in range(n):
        ans[i] = i + 1

    for i in range(n):
        cur = 0
        for j in range(0, n, i + 1):
            ans[i + j], cur = cur, ans[i + j]
        ans[i + n] = cur

    print(' '.join(map(str, ans[n:])))