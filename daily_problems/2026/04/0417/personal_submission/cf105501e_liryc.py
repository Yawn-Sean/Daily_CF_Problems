'''
https://codeforces.com/gym/105501/my#
'''
# KMP

def solve(n: int, m: int, s: list[int], a: list[list[int]]) -> int:
    kmp = KMP(s)
    for i, r in enumerate(a):
        if ~kmp.circle_index(r):
            return i + 1
    return -1
