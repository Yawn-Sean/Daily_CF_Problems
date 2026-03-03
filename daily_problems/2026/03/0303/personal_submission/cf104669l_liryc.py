'''
https://codeforces.com/gym/104669/submission/365190720
'''
# math
def solve(a: int, b: int) -> int:
    sm = a * b + (b - 1) * b // 2
    if b & 3 == 0:
        return sm >> 1
    def check(x):
        nonlocal sm, a, b
        for c in range(1, b):
            l = a * c + (c - 1) * c // 2
            r = a * c + (b - 1 + b - c) * c // 2
            if r - r % x >= l:
                return True
        return False
    ans = 1
    for x in range(2, sm):
        if x * x > sm:
            break
        if sm % x == 0:
            if check(sm // x):
                return sm // x
            elif x > ans and check(x):
                ans = x
    return ans
