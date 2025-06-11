'''
https://codeforces.com/problemset/submission/272/314992687
'''
# 乘法原理+细节处理
def solve(n: int, a: list[int], b: list[int], m: int) -> int:
    n2 = sum(x == y for x, y in zip(a, b))
    ans = 1
    for _, g in groupby(sorted(a + b)):
        c = sum(1 for _ in g)
        for e in range(2, c + 1):
            d = e
            while n2 and d & 1 == 0:
                d >>= 1
                n2 -= 1
            ans = ans * d % m
    return ans
