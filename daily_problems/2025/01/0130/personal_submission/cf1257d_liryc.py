'''
https://codeforces.com/problemset/submission/1257/303605378
'''
# 对于每一个i，存在一个固定的最优解k，使得存在一个英雄退治连续k个怪兽
def solve(n: int, m: int, a: list[int], b: list[tuple[int, int]]):
    c = []
    for p, s in sorted(b):
        while c and s >= c[-1][1]:
            c.pop()
        c.append((p, s))
    ans, k, hp, hs = 0, 0, 10**9, 0
    for x in a:
        k += 1
        if x > c[-1][0]:
            return -1
        elif x > hp:
            hp, hs = c[bisect_left(c, (x, 0))]
            if hs < k:
                ans += 1
                k = 1
        else: # x <= hp
            if hs < k:
                ans += 1
                hp, hs = c[bisect_left(c, (x, 0))]
                k = 1
    return ans
