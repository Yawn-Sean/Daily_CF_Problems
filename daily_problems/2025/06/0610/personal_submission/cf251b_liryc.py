'''
https://codeforces.com/problemset/submission/251/323737932
'''
# permutations
def solve(n: int, k: int, q: list[int], s: list[int]) -> bool:
    for i in range(n):
        q[i] -= 1
        s[i] -= 1
    a = list(range(n))
    r = list(sorted(range(n), key = lambda j: q[j]))
    if a == s:
        return False
    b, f = 0, 0
    while a != s:
        if f == k:
            f = -1
            break
        a[:] = (a[q[i]] for i in range(n))
        f += 1
    if f >= 0 and k - f & 1 == 0 and (f > 1 or k == 1 or r != s):
        return True
    a[:] = range(n)
    while a != s:
        if b == k:
            b = -1
            break
        a[:] = (a[r[i]] for i in range(n))
        b += 1
    return b >= 0 and k - b & 1 == 0 and (b > 1 or k == 1 or q != s)
