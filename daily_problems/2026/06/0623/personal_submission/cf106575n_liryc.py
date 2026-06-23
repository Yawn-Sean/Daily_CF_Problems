'''
https://codeforces.com/gym/106575/submission/379872187
binary search
'''
def solve(n: int, ca: int, cb: int, a: list[int], b: list[int]) -> int:
    if a[0] < b[0]:
        return 0
    sa, ia = [a[0]], [0]
    for i, x in enumerate(a):
        if x < sa[-1]:
            sa.append(x)
            ia.append(i)
    sb, ib = [b[0]], [0]
    for i, x in enumerate(b):
        if x > sb[-1]:
            sb.append(x)
            ib.append(i)
    ans = -1
    for i, xa in enumerate(sa):
        ida = ia[i]
        j = bisect(sb, xa)
        idb = ib[j]
        ans = pmin(ans, ida * ca + idb * cb)
    return ans
