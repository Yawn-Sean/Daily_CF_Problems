# Submission link: https://codeforces.com/contest/713/submission/272886095
def main():
    def query(x1, y1, x2, y2):
        print('?', x1, y1, x2, y2, flush=True)
        return II()

    def solve(x1, y1, x2, y2):
        l, r = x1, x2
        while l <= r:
            m = (l + r) // 2
            if query(m, y1, x2, y2):
                l = m + 1
            else:
                r = m - 1
        rectangles.append(r)
        
        l, r = y1, y2
        while l <= r:
            m = (l + r) // 2
            if query(x1, m, x2, y2):
                l = m + 1
            else:
                r = m - 1
        rectangles.append(r)
        
        l, r = x1, x2
        while l <= r:
            m = (l + r) // 2
            if query(x1, y1, m, y2):
                r = m - 1
            else:
                l = m + 1
        rectangles.append(l)

        l, r = y1, y2
        while l <= r:
            m = (l + r) // 2
            if query(x1, y1, x2, m):
                r = m - 1
            else:
                l = m + 1
        rectangles.append(l)


    n = II()
    l, r = 1, n
    while l <= r:
        m = (l + r) // 2
        if query(1, 1, m, n):
            r = m - 1
        else:
            l = m + 1

    rectangles = []

    if l < n and query(l + 1, 1, n, n):
        solve(1, 1, l, n)
        solve(l + 1, 1, n, n)
    else:
        l, r = 1, n
        while l <= r:
            m = (l + r) // 2
            if query(1, 1, n, m):
                r = m - 1
            else:
                l = m + 1
        solve(1, 1, n, l)
        solve(1, l + 1, n, n)

    print('!', *rectangles)