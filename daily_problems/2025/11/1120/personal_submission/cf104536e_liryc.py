'''
https://codeforces.com/gym/104536/submission/349789283
'''
# 直接应用二分求LIS的算法
def solve(n: int, a: list[int], b: list[int]) -> int:
    sa = []
    for x, y in zip(a, b):
        one = False
        i, j = -1, -1
        if x == y or not sa:
            one = True
            i = bisect_left(sa, x) if sa else 0
        else:
            i = bisect_left(sa, x)
            j = bisect_left(sa, y)
            if i == j:
                one = True
        if one:
            z = pmin(x, y)
            if i == len(sa):
                sa.append(z)
            else:
                sa[i] = z
        else:
            if i == len(sa):
                sa.append(x)
            else:
                sa[i] = x
            if j == len(sa):
                sa.append(y)
            else:
                sa[j] = y
    return len(sa)
