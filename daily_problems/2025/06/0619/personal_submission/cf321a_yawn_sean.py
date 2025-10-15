# Submission link: https://codeforces.com/problemset/submission/2044/324960054#
def main():
    a, b = MII()

    dirs = {}
    dirs['U'] = (0, 1)
    dirs['D'] = (0, -1)
    dirs['L'] = (-1, 0)
    dirs['R'] = (1, 0)

    s = I()

    x, y = 0, 0

    for c in s:
        dx, dy = dirs[c]
        x += dx
        y += dy

    cur_x, cur_y = 0, 0

    def check():
        step = 0
        if x: step = (a - cur_x) // x
        if y: step = (b - cur_y) // y
        return step >= 0 and cur_x + step * x == a and cur_y + step * y == b

    for c in s:
        dx, dy = dirs[c]
        
        if check():
            exit(print('Yes'))
        
        cur_x += dx
        cur_y += dy

    print('No')