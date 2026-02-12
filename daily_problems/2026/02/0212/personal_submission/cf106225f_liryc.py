'''
https://codeforces.com/gym/106225/submission/362567954
'''
# find the rules
def solve(n: int, a: list[int]) -> int:
    for j in range(1, n):
        x, y = a[j - 1], a[j]
        if y <= x:
            return x // (y - 1)
    x, y = a[-2], a[-1]
    return max(y - x, y // (y - x))
