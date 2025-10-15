'''
https://codeforces.com/problemset/submission/733/310504977
'''
# 力扣 001 两数之和
def solve(n: int, a: list[list[int]]) -> list[int]:
    maxi1 = max(range(n), key = lambda i: min(a[i]))
    di = {}
    max2 = (0, 0, 0)
    for i, r in enumerate(a):
        x, y, z = sorted(r)
        if (x, y) in di:
            t, j = di[(x, y)]
            s = min(x, y, z + t)
            if s > max2[0]:
                max2 = (s, i, j)
        if (y, z) in di:
            t, j = di[(y, z)]
            s = min(y, z, x + t)
            if s > max2[0]:
                max2 = (s, i, j)
        if (x, z) in di:
            t, j = di[(x, z)]
            s = min(x, z, y + t)
            if s > max2[0]:
                max2 = (s, i, j)

        if not (x, y) in di or di[(x, y)][0] < z:
            di[(x, y)] = (z, i)
        if not (y, z) in di or di[(y, z)][0] < x:
            di[(y, z)] = (x, i)
        if not (x, z) in di or di[(x, z)][0] < y:
            di[(x, z)] = (y, i)
    return [maxi1 + 1] if min(a[maxi1]) > max2[0] else [max2[1] + 1, max2[2] + 1]
