'''
https://codeforces.com/gym/105442/submission/379060200
'''
def solve(n: int, g: list[list[int]]) -> int:
    return min(min(a + d, b + e, a + c + e, b + c + d) for a, b, c, d, e in g)
