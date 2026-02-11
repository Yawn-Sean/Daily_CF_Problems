'''
https://codeforces.com/gym/105876/submission/362346192
'''
def solve(n: int) -> list[int]:
    if n & 3 == 3:
        return [-1]
    a = list(range(1, n + 1))
    for i in range(3, n, 4):
        a[i - 1], a[i] = a[i], a[i - 1]
    return a