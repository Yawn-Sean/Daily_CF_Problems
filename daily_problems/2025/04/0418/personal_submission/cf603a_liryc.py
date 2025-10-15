'''
https://codeforces.com/problemset/submission/603/316037338
'''
def solve(n: int, s: str) -> int:
    return min(n, sum(a != b for a, b in pairwise(s)) + 3)
