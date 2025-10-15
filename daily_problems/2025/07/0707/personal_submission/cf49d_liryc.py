'''
https://codeforces.com/problemset/submission/49/327859962
'''
def solve(n: int, s: str) -> int:
    m = 0
    for i, c in enumerate(s):
        if (c == '1') != (i & 1 != 0):
            m += 1
    return min(m, n - m)