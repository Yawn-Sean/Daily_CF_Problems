'''
https://codeforces.com/problemset/submission/595/310653346
'''
# calc each part
def solve(n: int, k: int, a: list[int], b: list[int]) -> int:
    def calc(a, b):
        nonlocal k
        return (10 ** k - 1) // a - ((b + 1) * 10 ** (k - 1) - 1) // a + (b * 10 ** (k - 1) - 1) // a + 1
    return reduce(mul, (calc(ai, bi) for ai, bi in zip(a, b))) % 1000000007
