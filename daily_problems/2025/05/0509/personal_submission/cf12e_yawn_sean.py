# Submission link: https://codeforces.com/contest/12/submission/318888682
def main():
    n = II()

    ans = [[0] * n for _ in range(n)]

    for i in range(n - 1):
        for j in range(n - 1):
            ans[i][j] = (i + j) % (n - 1) + 1

    for i in range(n):
        ans[-1][i] = ans[i][i]
        ans[i][-1] = ans[i][i]
        ans[i][i] = 0

    print('\n'.join(' '.join(map(str, x)) for x in ans))