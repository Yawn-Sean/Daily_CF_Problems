'''
https://codeforces.com/gym/106141/submission/374963459
simple math, enumeration
'''
def solve(n: int, a: list[int]) -> int:
    x1, y1 = sum(abs(x) for x in a), n
    x2, y2 = x1, y1
    si = list(sorted(range(n), key=lambda i: abs(a[i]), reverse=True))
    ans_k = 0
    for k in range(1, n + 1):
        j = si[k - 1]
        x2, y2 = x2 + 2 * abs(a[j]), y2 + 8
        if x2 * x2 * y1 > x1 * x1 * y2: 
            ans_k, x1, y1 = k, x2, y2
    b = [0] * n
    for i in range(ans_k):
        b[si[i]] = 3 if a[si[i]] > 0 else -3
    for i in range(n):
        if not b[i]:
            b[i] = 1 if a[i] > 0 else -1
    return b
