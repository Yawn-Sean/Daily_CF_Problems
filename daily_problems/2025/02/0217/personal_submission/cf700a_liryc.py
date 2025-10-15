'''
https://codeforces.com/problemset/submission/700/306480934
'''
def solve(n: int, l: int, v1: int, v2: int, k: int) -> float:
    g = (n + k - 1) // k
    return l / v2 * (2 * v2 * (g - 1) + v1 + v2) / (2 * v1 * (g - 1) + (v1 + v2))
