'''
https://codeforces.com/problemset/submission/440/322008210
'''
# array, greedy
def solve(n: int, a: list[int]) -> int:
    sm = sum(a)
    m = sm // n
    d, ans = 0, 0
    for x in a:
        y = x + d
        d = y - m
        ans += abs(d)
    return ans
