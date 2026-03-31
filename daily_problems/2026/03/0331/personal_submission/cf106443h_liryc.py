'''
https://codeforces.com/gym/106443/submission/368919906
'''
# LIS
def solve(n: int, pa: list[list[int]]) -> int:
    sa = []
    for x, y in pa:
        if y - x >= 0:
            sa.append(enc(y + x, y - x))
    sa.sort()
    lis = []
    for z in sa:
        _, y = dec(z)
        if len(lis) == 0 or lis[-1] <= y:
            lis.append(y)
        else:
            lis[bisect_right(lis, y)] = y
    return len(lis)
