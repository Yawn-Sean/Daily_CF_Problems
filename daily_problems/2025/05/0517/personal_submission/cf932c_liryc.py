'''
https://codeforces.com/problemset/submission/932/319995962
'''
# math, construction of permutation
def solve(n: int, a: int, b: int) -> list[int]:
    m = -1
    for c in range(0, n + 1, a):
        if (n - c) % b == 0:
            m = c
            break
    if m < 0:
        return [-1]
    c, i = 0, 0
    ans = [0] * n
    while c < n:
        c = c + a if c < m else c + b
        ans[i] = c
        i += 1
        while i < c:
            ans[i] = i
            i += 1
    return ans
