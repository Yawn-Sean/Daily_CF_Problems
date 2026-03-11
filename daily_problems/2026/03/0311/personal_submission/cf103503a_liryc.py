'''
https://codeforces.com/gym/103503/submission/366212169
'''
# binary search
def solve(n: int, s: int, a: list[int]) -> int:
    a.sort()
    ss = [0] * n
    for i in range(-1, -n - 1, -1):
        ss[i] = a[i] + ss[i + 1]
    def check(m):
        nonlocal a, ss
        j = bisect_right(a, m)
        return (1 + m) * m // 2 + (0 if j >= n else ss[j])
    t = bisect_left(range(s + 1), s, key=check)
    j = bisect_right(a, t)
    return n - j + t
