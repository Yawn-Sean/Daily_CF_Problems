'''
https://codeforces.com/problemset/submission/471/331535004
'''
# counting
def solve(n: int) -> int:
    r = 3 - n % 3

    def check(m):
        nonlocal r, n
        h = r + m * 3
        return h + n < 3 * (1 + h) * h >> 1

    return bisect_right(range(10 ** 12), 0, key=check)
