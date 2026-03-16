'''
https://codeforces.com/gym/106259/submission/366872779
'''
def solve(n: int, a: list[int]) -> int:
    return min(x ^ y for x, y in pairwise(sorted(a)))
