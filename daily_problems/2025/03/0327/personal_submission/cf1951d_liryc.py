'''
https://codeforces.com/problemset/submission/1951/312639082
'''
def solve(n: int, k: int) -> list[int]:
    if n == k:
        return [1]
    elif n < (n - k + 1 << 1):
        return [n - k + 1, 1]
    else:
        return []
