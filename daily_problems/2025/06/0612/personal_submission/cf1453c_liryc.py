'''
https://codeforces.com/problemset/submission/1453/323980619
'''
# greedy
def solve(n: int, a: list[list[int]]) -> list[int]:
    b = [[n, -1, n, -1] for _ in range(10)]
    for i in range(n):
        for j in range(n):
            c = a[i][j]
            b[c][0] = pmin(b[c][0], i)
            b[c][1] = pmax(b[c][1], i)
            b[c][2] = pmin(b[c][2], j)
            b[c][3] = pmax(b[c][3], j)
    ans = [0] * 10
    for i in range(n):
        for j in range(n):
            c = a[i][j]
            if i > b[c][0]:
                ans[c] = pmax(ans[c], (i - b[c][0]) * pmax(j, n - 1 - j))
            if i < b[c][1]:
                ans[c] = pmax(ans[c], (b[c][1] - i) * pmax(j, n - 1 - j))
            if j > b[c][2]:
                ans[c] = pmax(ans[c], (j - b[c][2]) * pmax(i, n - 1 - i))
            if j < b[c][3]:
                ans[c] = pmax(ans[c], (b[c][3] - j) * pmax(i, n - 1 - i)) 
    return ans

