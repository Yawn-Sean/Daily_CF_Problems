'''
https://codeforces.com/gym/102986/submission/368456919
'''
def solve(n: int, w: int, a: list[int]) -> float:
    return sum(((i << 1) - (n - 1)) * x for i, x in enumerate(sorted(a))) * 2 / n + w
