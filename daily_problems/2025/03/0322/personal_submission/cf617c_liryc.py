'''
https://codeforces.com/problemset/submission/617/311769109
'''
# 排序
def solve(n: int, x1: int, y1: int, x2: int, y2: int, flowers: list[list[int]]) -> int:
    rq1, rq2 = 0, 0
    sa = []
    for x, y in flowers:
        rq = (x - x1) ** 2 + (y - y1) ** 2
        sa.append((rq, x, y))
    sa.sort()
    ans = rq1 = sa[-1][0]
    for i in range(n - 1, -1, -1):
        _, x, y = sa[i]
        rq1 = sa[i - 1][0] if i else 0
        rq2 = max(rq2, (x - x2) ** 2 + (y - y2) ** 2)
        ans = min(ans, rq1 + rq2)
    return ans