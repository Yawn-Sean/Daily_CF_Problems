'''
https://codeforces.com/gym/103855/submission/343644412
'''
# array segments, sorting
def solve(n: int, t: int, S: str) -> str:
    a = [c for c in S]
    def rpssort(start, end, ms):
        nonlocal a, t
        i = start
        for j in range(start + 1, end):
            i = max(i, j - t)
            if a[j] == ms[1]:
                while i < j and a[i] != ms[0]:
                    i += 1
                a[i], a[j] = a[j], a[i]
    i, r, p, s = 0, 0, 0, 0
    for j in range(n):
        c = a[j]
        r, p, s = r + (c == 'R'), p + (c == 'P'), s + (c == 'S')
        if sum((r != 0, p != 0, s != 0)) == 3:
            rpssort(i, j, 'SP' if c == 'R' else 'RS' if c == 'P' else 'PR')
            i = j
            r, p, s = 0 + (c == 'R'), 0 + (c == 'P'), 0 + (c == 'S')
    if i < n - 1:
        rpssort(i, n, 'SP' if r == 0 else 'RS' if p == 0 else 'PR')
    return ''.join(a)
