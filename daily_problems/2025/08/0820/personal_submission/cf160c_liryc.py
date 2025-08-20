'''
https://codeforces.com/problemset/submission/160/334630574
'''
# sorting + grouping
def solve(n: int, k: int, a: list[int]) -> list[int]:
    k -= 1
    a.sort()
    for x, g in groupby(a):
        c = sum(1 for _ in g)
        if c * n <= k:
            k -= c * n
        else:
            return [x, a[k // c]]
