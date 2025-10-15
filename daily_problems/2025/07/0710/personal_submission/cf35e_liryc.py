'''
https://codeforces.com/problemset/submission/35/328348709
'''
# LC218. 天际线问题
# priority queue
def solve(n: int, a: list[list[int]]) -> list[str]:
    for i in range(n):
        h, l, r = a[i]
        a[i][:] = l, r, h
    a.sort()
    ans, hp = [], []
    x, y, i = a[0][0], 0, 0
    while hp or i < n:
        # fix the next x
        x = 1000000001
        if hp:
            x = hp[0][1]
        if i < n and a[i][0] < x:
            x = a[i][0]

        # remove building
        while hp and hp[0][1] <= x:
            heappop(hp)
        # add building
        while i < n and a[i][0] <= x:
            l, r, h = a[i]
            i += 1
            heappush(hp, (~h, r))

        # calc hight
        y1 = 0
        if hp:
            y1 = ~hp[0][0]
        if y1 != y:
            ans.append(f"{x} {y}")
            y = y1
            ans.append(f"{x} {y}")
    return ans
