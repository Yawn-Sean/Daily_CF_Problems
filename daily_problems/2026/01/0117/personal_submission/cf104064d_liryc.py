'''
https://codeforces.com/gym/104064/submission/358104636
'''
# math
def solve(n: int, stars: list[list[int]]) -> int:
    if n == 1:
        return 4
    MAXL = 1 << 30
    max_x, min_x, max_y, min_y = -MAXL, MAXL, -MAXL, MAXL
    for x, y in stars:
        x, y = x + y, x - y
        max_x = max(max_x, x)
        min_x = min(min_x, x)
        max_y = max(max_y, y)
        min_y = min(min_y, y)
    return max_x - min_x + max_y - min_y + 4 + (max_x == min_x or max_y == min_y)
