'''
https://codeforces.com/contest/1176/submission/361082053
'''
# simple math, counter
def solve(n: int, a: list[int]) -> int:
    c1, c2, c3, c4, c5, c6 = 0, 0, 0, 0, 0, 0
    for x in a:
        if x == 4:
            c1 += 1
        elif x == 8:
            if c1:
                c1, c2 = c1 - 1, c2 + 1
        elif x == 15:
            if c2:
                c2, c3 = c2 - 1, c3 + 1
        elif x == 16:
            if c3:
                c3, c4 = c3 - 1, c4 + 1
        elif x == 23:
            if c4:
                c4, c5 = c4 - 1, c5 + 1
        elif x == 42:
            if c5:
                c5, c6 = c5 - 1, c6 + 1
    return n - c6 * 6
