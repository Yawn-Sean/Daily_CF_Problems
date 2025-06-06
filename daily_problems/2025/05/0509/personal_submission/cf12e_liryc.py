'''
https://codeforces.com/problemset/submission/12/318901241
'''
def solve(n: int) -> list[list[int]]:
    ans = [[0] * n for _ in range(n)]

    for i in range(n - 1):
        for j in range(n - 1):
            ans[i][j] = (i + j) % (n - 1) + 1

    for i in range(n):
        ans[-1][i] = ans[i][i]
        ans[i][-1] = ans[i][i]
        ans[i][i] = 0

    return ans