'''
https://codeforces.com/problemset/submission/58/325873761
'''
# counter
def solve(n: int, a: list[int]) -> int:
    b = [0] * n
    i, j, k = 0, n - 1, 1
    while i <= j:
        b[i] = b[j] = k
        i, j, k = i + 1, j - 1, k + 1
    cn = [0] * 100000
    for i in range(n):
        d = a[i] - b[i]
        if d >= 0:
            cn[d] += 1
    return n - max(cn)
