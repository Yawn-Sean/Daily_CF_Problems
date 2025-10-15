'''
https://codeforces.com/problemset/submission/45/328836995
'''
# constructive
def solve(n: int, m: int) -> list[list[int]]:
    if n == m == 1:
        return [[1]]
    elif n + m < 5:
        return [[-1]]
    a = [[0] * m for _ in range(n)]
    small, big = 1, n * m // 2 + 1
    for i in range(n):
        for j in range(m):
            if i + j & 1:
                a[i][j] = small
                small += 1
            else:
                a[i][j] = big
                big += 1
    return a
