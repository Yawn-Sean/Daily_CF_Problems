'''
https://codeforces.com/gym/106527/submission/375291934
simple math, greedy
'''
def solve(n: int, p: int, x: int, ka: list[int]) -> int:
    ka.sort(reverse=True)
    s = sum(ka)
    ps = 0
    pa = [0] * (n + 1)
    for k in ka:
        pa[0] += 1
        pa[k] -= 1
    for i in range(1, n + 1):
        pa[i] += pa[i - 1]
    for m in range(n):
        ps += pa[m - 1]
        if s - ps <= x * (n - m):
            return m
    return n
