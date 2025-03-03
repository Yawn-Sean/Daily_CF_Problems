'''
https://codeforces.com/problemset/submission/1599/308066339
'''
def solve(n: int, p: float) -> int:
    return min(x for x in range(n + 1) if (x * (x - 1) * (x - 2) // 6 + x * (x - 1) // 2 * (n - x) + x * (n - x) * (n - x - 1) // 2 / 2) / (n * (n - 1) * (n - 2) // 6) >= p)
