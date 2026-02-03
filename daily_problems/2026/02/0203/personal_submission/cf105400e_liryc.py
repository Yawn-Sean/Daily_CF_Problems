'''
https://codeforces.com/gym/105400/submission/361223116
'''
# simple math and counting
def solve(n: int, a: list[int]) -> int:
    min_x, max_x = min(a), max(a)
    ans = 1
    for x in a:
        if min_x == max_x:
            ans *= 10
        elif x == min_x:
            ans *= x
        elif x == max_x:
            ans *= 10 - x + 1
    return ans
