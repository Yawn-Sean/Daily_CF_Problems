'''
https://codeforces.com/gym/106259/submission/374143195
permutations
'''

def solve(n: int, a: list[int]) -> bool:
    return max(a[0], a[-1]) == 2 and min(a[0], a[-1]) == 1
