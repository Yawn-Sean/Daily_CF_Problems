'''
https://codeforces.com/problemset/submission/67/332307869
https://codeforces.com/problemset/submission/67/332308402
'''
# LIS
def solve(n: int, xa: list[int], ya: list[int]) -> int:
    sa = [[0, 0] for _ in range(n)]
    for i, y in enumerate(ya):
        sa[y - 1][0] = i
    for i, x in enumerate(xa):
        sa[x - 1][1] = i
    sa.sort(reverse=True)
    a = []
    ans = 0
    for y, x in sa:
        if not a or a[-1] < x:
            a.append(x)
            ans = len(a)
        else:
            i = bisect_left(a, x)
            a[i] = x
    return ans
