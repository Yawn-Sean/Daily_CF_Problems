'''
https://codeforces.com/problemset/submission/375/318055545
'''
# prefix sum
def solve(n: int, m: int, sa: list[str]) -> int:
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m - 1, -1, -1):
            a[i][j] = 1 if sa[i][j] == '1' else 0
            if a[i][j] and j < m - 1:
                a[i][j] += a[i][j + 1]
    ans = 0
    for j in range(m):
        ps = [0] * (m - j + 2)
        for i in range(n):
            ps[a[i][j]] += 1
        for k in range(m - j, 0, -1):
            ps[k] += ps[k + 1]
            ans = max(ans, ps[k] * k)
    return ans
