'''
https://codeforces.com/gym/105314/submission/350948606
'''
def solve(n: int, m: int, a: list[int]) -> int: 
    a.sort()
    
    def check(x):
        nonlocal a, m
        j, c = 0, 0
        for i in range(n):
            while j < n and a[j] - a[i] < x:
                j += 1
            c += (n - j) * 2
        return c <= m
    
    bound = bisect_left(range(10 ** 7 + 1), True, key=check)
    ps = [0] * (n + 1)
    for i in range(n):
        ps[i + 1] = ps[i] + a[i]
    ans, j, c = 0, 0, 0
    for i in range(n):
        while j < n and a[j] - a[i] < bound:
            j += 1
        c += (n - j) * 2
        ans += (ps[n] - ps[j] - (n - j) * a[i]) * 2
    ans += (m - c) * (bound - 1)
    return ans
