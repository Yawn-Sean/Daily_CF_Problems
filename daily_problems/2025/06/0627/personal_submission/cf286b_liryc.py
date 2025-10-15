'''
https://codeforces.com/problemset/submission/286/326300395
'''
def solve(n: int) -> list[int]:
    ans = list(range(1, n + 1)) + [0] * n
    for i in range(n):
        c = 0
        for j in range(0, n, i + 1):
            ans[i + j], c = c, ans[i + j]
        ans[i + n] = c
    return ans[n:]
