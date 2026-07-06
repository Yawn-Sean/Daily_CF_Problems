'''
https://codeforces.com/gym/103821/submission/381378169
simple math
'''
def solve(n: int) -> list[int]:
    r = isqrt(n + 1)
    if r * r == n + 1:
        return list(range(1, r))
    else:
        return [-1]
