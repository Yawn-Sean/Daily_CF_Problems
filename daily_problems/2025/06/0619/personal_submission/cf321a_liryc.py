'''
https://codeforces.com/problemset/submission/321/325086339
'''
# (OTK) grid move, 分类讨论
def solve(a: int, b: int, s: str) -> bool:
    if a == 0 and b == 0:
        return True
    rx, ry = s.count('R') - s.count('L'), s.count('U') - s.count('D')
    x, y = 0, 0
    for c in s:
        if c == 'U':
            y += 1
        elif c == 'D':
            y -= 1
        elif c == 'L':
            x -= 1
        else:
            x += 1

        if rx == 0 and ry == 0:
            if x == a and y == b:
                return True
        elif rx == 0:
            if (b - y) % ry == 0 and (b - y) // ry >= 0:
                if x == a:
                    return True
        else:
            if (a - x) % rx == 0 and (a - x) // rx >= 0:
                r = (a - x) // rx
                if ry * r + y == b:
                    return True
    return False
