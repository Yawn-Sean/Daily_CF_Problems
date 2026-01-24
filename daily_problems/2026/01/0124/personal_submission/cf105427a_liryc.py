'''
https://codeforces.com/gym/105427/submission/359354321
'''
# recursive
def solve(n: int, k: int, d: int = 1, c: int = 0, t: int = 0) -> int:
    if n == 0:
        return 0
    elif t == k:
        return c + (n - d)
    l = d * k + 1
    if n >= l:
        return solve(n, k, l, c * k + 1, t + 1)
    else:
        v, r = divmod(n, d)
        return c * v + solve(r, k)
