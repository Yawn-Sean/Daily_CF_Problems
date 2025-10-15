'''
https://codeforces.com/problemset/submission/260/328178439
'''
# simple math and counting
def solve(n: int, x: int, a: list[int]) -> list[int]:
    m = min(a)
    c = m * n
    ans = [t - m for t in a]
    i = x - 1
    while ans[i]:
        c += 1
        ans[i] -= 1
        i = (i - 1) % n
    ans[i] = c
    return ans
