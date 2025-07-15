'''
https://codeforces.com/problemset/submission/1991/328987929
'''
def solve(n: int) -> tuple[int, list[int]]:
    if n <= 5:
        return n // 2 + 1, [x // 2 + 1 for x in range(1, n + 1)]
    else:
        return 4, [x % 4 + 1 for x in range(n)]
