'''
https://codeforces.com/gym/106539/submission/376969074
'''
def solve(n: int, m: int) -> int:
    return min(n, m + 2 >> 1)
