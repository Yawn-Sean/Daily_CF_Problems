'''
https://codeforces.com/problemset/submission/269/332658762
'''
# simple math
def solve(n: int, k: list[int], a: list[int]):
    ans = 0
    for v, c in zip(k, a):
        p, m = v + 1, 4
        while m < c:
            p += 1
            m <<= 2
        if p > ans:
            ans = p
    return ans
