'''
https://codeforces.com/problemset/submission/373/320989481
'''
# binary search
def solve(w: int, m: int, k: int) -> int:
    def calc(x):
        ans, b = 0, 1
        while x >= b:
            ans += x - b + 1
            b *= 10
        return ans
    w = w // k + calc(m - 1)
    return bisect_right(range(2 * 10 ** 16), w, key = calc) - m
