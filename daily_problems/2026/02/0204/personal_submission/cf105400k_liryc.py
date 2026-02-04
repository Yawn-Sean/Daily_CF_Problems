'''
https://codeforces.com/gym/105400/submission/361378605
'''
def solve(n: int, a: list[int]) -> bool:
    sa = list(sorted(range(n), key=lambda i: a[i]))
    ft = FenwickTree(n)
    res = [0] * n
    for i in range(n - 1, -1, -1):
        res[i] = ft.rangesum(0, sa[i])
        ft.add(sa[i], 1)
    for i in range(1, n):
        res[i] += res[i - 1]
    for i in range(n):
        if a[sa[i]] < res[i]:
            return False
    return True
