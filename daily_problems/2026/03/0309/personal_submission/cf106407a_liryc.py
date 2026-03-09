'''
https://codeforces.com/gym/106407/submission/365942755
'''
# alice and bob game
def solve(m: int, n: int, k: int) -> bool:
    return k >= (2 - (m & 1)) * (2 - (n & 1))
