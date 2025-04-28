'''
https://codeforces.com/problemset/submission/317/316168156
'''
# same as fib
def solve(x: int, y: int, m: int) -> int:
    if x >= m or y >= m:
        return 0
    elif x <= 0 and y <= 0:
        return -1
    ans = 0
    if x > y:
        x, y = y, x
    if x < 0:
        ans = (y - x - 1) // y
        x += y * ans
    while y < m:
        ans += 1
        x, y = y, x + y
    return ans