'''
https://codeforces.com/gym/101466/submission/338291788
'''
# KMP, binary search
def solve(a: str, b: str, n: int) -> str:
    m = bisect_right(range(len(b) + 1), 0, key=lambda t: prep(b[:t] + '|' + a).count(t) < n) - 1
    if m == 0:
        return "IMPOSSIBLE"
    else:
        return b[:m]
