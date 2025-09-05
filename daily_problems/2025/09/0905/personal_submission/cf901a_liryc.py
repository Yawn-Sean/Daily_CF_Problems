'''
https://codeforces.com/problemset/submission/901/336961843
'''
# tree constructive
def solve(h: int, a: list[int]) -> list[list[int]]:
    if all(x == 1 or y == 1 for x, y in pairwise(a)):
        return []
    r = 0
    m = 0
    t1 = [0] * (sum(a))
    t2 = [0 for _ in t1]
    for n in a:
        if n > 1 and m > 1:
            for i in range(r, r + n):
                t1[i] = r - (i & 1)
                t2[i] = r
        else:
            for i in range(r, r + n):
                t1[i] = r
                t2[i] = r
        r += n
        m = n
    return [t1, t2]
