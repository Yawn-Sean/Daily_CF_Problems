'''
https://codeforces.com/problemset/submission/380/312928219
'''
# binary search
def solve(m: int, stages: list[list[int]], n: int, queries: list[int]) -> list[int]: 
    i = 0
    pre = []
    sa = []
    for a in stages:
        if a[0] == 1:
            sa.append((i, 1, a[1]))
            i += 1
            if len(pre) < 100000:
                pre.append(a[1])
        else:
            sa.append((i, 2, a[1]))
            i += a[1] * a[2]
            if len(pre) < 100000:
                if len(pre) + a[1] * a[2] <= 100010:
                    pre += pre[:a[1]] * a[2]
                else:
                    for _ in range(a[2]):
                        pre += pre[:a[1]]
                        if len(pre) >= 100000:
                            break
    def query(i: int):
        nonlocal pre, sa
        j = bisect_right(sa, (i, 3, 0)) - 1
        if sa[j][1] == 1:
            return sa[j][2]
        else:
            return pre[(i - sa[j][0]) % sa[j][2]]

    return [query(q - 1) for q in queries]
